/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "always.h"

#include "movie_decoder.h"

#include "ccfile.h"
#include "dbgprint.h"

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/error.h>
#include <libavutil/pixfmt.h>
#include <libswresample/swresample.h>
#include <libswscale/swscale.h>
}

#include <algorithm>
#include <cerrno>
#include <cmath>
#include <cstdint>
#include <deque>
#include <limits>
#include <memory>
#include <utility>
#include <vector>


namespace {

constexpr int AvioBufferSize = 32 * 1024;
constexpr std::size_t VideoQueueCapacity = 2;
constexpr std::size_t PendingVideoByteLimit = 16 * 1024 * 1024;
constexpr int MaximumAudioGapSeconds = 60;
constexpr double MaximumVideoGapSeconds = 60.0;


bool Is_Valid_Output_Size(int width, int height, int bytesperpixel)
{
	if (width <= 0 || height <= 0 || bytesperpixel <= 0
		|| width > std::numeric_limits<std::uint16_t>::max()
		|| height > std::numeric_limits<std::uint16_t>::max()) {
		return(false);
	}
	std::size_t rowbytes = static_cast<std::size_t>(width) * bytesperpixel;
	return(rowbytes <= static_cast<std::size_t>(std::numeric_limits<int>::max())
		&& static_cast<std::size_t>(height) <= std::numeric_limits<std::size_t>::max() / rowbytes);
}


struct PacketDeleter
{
	void operator()(AVPacket *packet) const
	{
		av_packet_free(&packet);
	}
};


using PacketPointer = std::unique_ptr<AVPacket, PacketDeleter>;


void Log_FFmpeg_Error(char const *operation, int error)
{
	char buffer[AV_ERROR_MAX_STRING_SIZE];
	av_strerror(error, buffer, sizeof(buffer));
	DebugString("FFmpeg movie decoder: %s: %s\n", operation, buffer);
}


int Read_Movie_File(void *opaque, unsigned char *buffer, int size)
{
	CCFileClass *file = static_cast<CCFileClass *>(opaque);
	int count = file->Read(buffer, size);
	return(count > 0 ? count : AVERROR_EOF);
}


std::int64_t Seek_Movie_File(void *opaque, std::int64_t offset, int origin)
{
	CCFileClass *file = static_cast<CCFileClass *>(opaque);
	origin &= ~AVSEEK_FORCE;
	if (origin == AVSEEK_SIZE) {
		return(file->Size());
	}
	if (origin != SEEK_SET && origin != SEEK_CUR && origin != SEEK_END) {
		return(AVERROR(EINVAL));
	}
	if (offset < std::numeric_limits<int>::min() || offset > std::numeric_limits<int>::max()) {
		return(AVERROR(EINVAL));
	}
	return(file->Seek(static_cast<int>(offset), origin));
}


double Stream_Start_Time(AVFormatContext const *format, AVStream const *stream)
{
	if (stream != nullptr && stream->start_time != AV_NOPTS_VALUE
		&& stream->time_base.num > 0 && stream->time_base.den > 0) {
		return(av_q2d(stream->time_base) * static_cast<double>(stream->start_time));
	}
	if (format->start_time != AV_NOPTS_VALUE) {
		return(static_cast<double>(format->start_time) / AV_TIME_BASE);
	}
	return(0.0);
}


int Swscale_Color_Space(AVColorSpace colorspace)
{
	switch (colorspace) {
		case AVCOL_SPC_BT709:
			return(SWS_CS_ITU709);
		case AVCOL_SPC_FCC:
			return(SWS_CS_FCC);
		case AVCOL_SPC_SMPTE240M:
			return(SWS_CS_SMPTE240M);
		default:
			return(SWS_CS_ITU601);
	}
}


class MovieInput
{
	public:
		explicit MovieInput(char const *filename) : File(filename) {}

		~MovieInput(void)
		{
			Close();
		}

		MovieInput(MovieInput const &) = delete;
		MovieInput & operator=(MovieInput const &) = delete;

		bool Open(void)
		{
			Close();
			if (File.Open(File.File_Name(), FileClass::READ) == 0) {
				return(false);
			}

			unsigned char *buffer = static_cast<unsigned char *>(av_malloc(AvioBufferSize));
			if (buffer == nullptr) {
				File.Close();
				return(false);
			}

			Io = avio_alloc_context(buffer, AvioBufferSize, 0, &File, &Read_Movie_File,
				nullptr, &Seek_Movie_File);
			if (Io == nullptr) {
				av_free(buffer);
				File.Close();
				return(false);
			}

			Format = avformat_alloc_context();
			if (Format == nullptr) {
				Close();
				return(false);
			}
			Format->pb = Io;
			Format->flags |= AVFMT_FLAG_CUSTOM_IO;

			int result = avformat_open_input(&Format, nullptr, nullptr, nullptr);
			if (result < 0) {
				Log_FFmpeg_Error("could not open movie", result);
				Close();
				return(false);
			}
			result = avformat_find_stream_info(Format, nullptr);
			if (result < 0) {
				Log_FFmpeg_Error("could not read stream information", result);
				Close();
				return(false);
			}
			return(true);
		}

		void Close(void)
		{
			if (Format != nullptr) {
				avformat_close_input(&Format);
			}
			if (Io != nullptr) {
				av_freep(&Io->buffer);
				avio_context_free(&Io);
			}
			if (File.Is_Open()) {
				File.Close();
			}
		}

		AVFormatContext * Get_Format(void) const { return(Format); }

	private:
		CCFileClass File;
		AVIOContext *Io = nullptr;
		AVFormatContext *Format = nullptr;
};

} // namespace


class MovieDecoder::Implementation
{
	public:
		Implementation(char const *filename, MoviePixelFormat format) :
			Input(filename),
			OutputFormat(format)
		{
		}

		~Implementation(void)
		{
			swr_free(&Resampler);
			sws_freeContext(Scaler);
			av_packet_free(&Packet);
			av_frame_free(&VideoDecodedFrame);
			av_frame_free(&AudioDecodedFrame);
			avcodec_free_context(&Video);
			avcodec_free_context(&Audio);
		}

		bool Open(bool decodeaudio)
		{
			if (!Input.Open()) {
				return(false);
			}

			AVFormatContext *format = Input.Get_Format();
			VideoStream = av_find_best_stream(format, AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0);
			if (VideoStream < 0) {
				Log_FFmpeg_Error("movie has no supported video stream", VideoStream);
				return(false);
			}
			if (!Open_Codec(VideoStream, &Video)) {
				return(false);
			}

			AVStream *videostream = format->streams[VideoStream];
			AVRational rate = av_guess_frame_rate(format, videostream, nullptr);
			double rawrate = rate.num != 0 && rate.den != 0 ? av_q2d(rate) : 0.0;
			FrameRate = rawrate > 0.0 && rawrate <= 1000.0 ? rawrate : 15.0;
			Width = Video->width;
			Height = Video->height;
			int bytesperpixel = 0;
			switch (OutputFormat) {
				case MOVIE_PIXEL_RGB565:
					bytesperpixel = sizeof(std::uint16_t);
					break;
				case MOVIE_PIXEL_BGRA8888:
					bytesperpixel = sizeof(std::uint32_t);
					break;
				default:
					return(false);
			}
			if (!Is_Valid_Output_Size(Width, Height, bytesperpixel)) {
				DebugString("FFmpeg movie decoder: unsupported video dimensions\n");
				return(false);
			}
			Pitch = Width * bytesperpixel;

			if (decodeaudio) {
				AudioStream = av_find_best_stream(format, AVMEDIA_TYPE_AUDIO, -1, -1, nullptr, 0);
				if (AudioStream >= 0 && !Open_Codec(AudioStream, &Audio)) {
					AudioStream = -1;
					avcodec_free_context(&Audio);
				}
			}

			TimelineOrigin = Stream_Start_Time(format, videostream);
			if (AudioStream >= 0) {
				TimelineOrigin = std::min(TimelineOrigin,
					Stream_Start_Time(format, format->streams[AudioStream]));
				AudioFormat.SampleRate = Audio->sample_rate;
				AudioFormat.Channels = Audio->ch_layout.nb_channels;
				if (!AudioFormat) {
					AudioStream = -1;
					avcodec_free_context(&Audio);
				}
			}

			VideoDecodedFrame = av_frame_alloc();
			AudioDecodedFrame = Audio != nullptr ? av_frame_alloc() : nullptr;
			Packet = av_packet_alloc();
			return(VideoDecodedFrame != nullptr && Packet != nullptr
				&& (Audio == nullptr || AudioDecodedFrame != nullptr));
		}

		bool Open_Codec(int streamindex, AVCodecContext **context)
		{
			AVStream *stream = Input.Get_Format()->streams[streamindex];
			AVCodec const *codec = avcodec_find_decoder(stream->codecpar->codec_id);
			*context = codec != nullptr ? avcodec_alloc_context3(codec) : nullptr;
			if (*context == nullptr) {
				return(false);
			}
			int result = avcodec_parameters_to_context(*context, stream->codecpar);
			if (result >= 0) {
				result = avcodec_open2(*context, codec, nullptr);
			}
			if (result < 0) {
				Log_FFmpeg_Error("could not initialize decoder", result);
				return(false);
			}
			return(true);
		}

		bool Pump(bool prefetchaudio)
		{
			if (Failed) {
				return(false);
			}

			for (;;) {
				if (!Drain_Decoders()) {
					Failed = true;
					return(false);
				}
				bool audioenough = !prefetchaudio || Audio == nullptr || AudioFinished
					|| AudioSamples.size() >= static_cast<std::size_t>(AudioFormat.SampleRate)
						* AudioFormat.Channels / 2;
				if (VideoFrames.size() >= VideoQueueCapacity && audioenough) {
					return(true);
				}
				if (VideoFrames.size() < VideoQueueCapacity && !PendingVideoPackets.empty()) {
					PacketPointer &packet = PendingVideoPackets.front();
					int result = avcodec_send_packet(Video, packet.get());
					if (result < 0) {
						Log_FFmpeg_Error("could not submit queued video packet", result);
						Failed = true;
						return(false);
					}
					PendingVideoBytes -= static_cast<std::size_t>(std::max(packet->size, 0));
					PendingVideoPackets.pop_front();
					continue;
				}
				if (DemuxFinished) {
					if (!PendingVideoPackets.empty()) {
						return(true);
					}
					if (!Flush_Decoders()) {
						Failed = true;
						return(false);
					}
					if (!Drain_Decoders()) {
						Failed = true;
						return(false);
					}
					if (VideoFinished) {
						return(true);
					}
					continue;
				}

				int result = av_read_frame(Input.Get_Format(), Packet);
				if (result < 0) {
					if (result != AVERROR_EOF) {
						Log_FFmpeg_Error("could not read movie packet", result);
						Failed = true;
						return(false);
					}
					DemuxFinished = true;
					continue;
				}

				AVCodecContext *decoder = nullptr;
				char const *operation = nullptr;
				if (Packet->stream_index == VideoStream
					&& VideoFrames.size() >= VideoQueueCapacity) {
					std::size_t packetsize = static_cast<std::size_t>(std::max(Packet->size, 0));
					if (packetsize > PendingVideoByteLimit - PendingVideoBytes) {
						DebugString("FFmpeg movie decoder: pending video packet limit exceeded\n");
						av_packet_unref(Packet);
						Failed = true;
						return(false);
					}
					PacketPointer queued(av_packet_clone(Packet));
					if (queued == nullptr) {
						av_packet_unref(Packet);
						Failed = true;
						return(false);
					}
					PendingVideoBytes += packetsize;
					PendingVideoPackets.push_back(std::move(queued));
					av_packet_unref(Packet);
					continue;
				} else if (Packet->stream_index == VideoStream) {
					decoder = Video;
					operation = "could not submit video packet";
				} else if (Packet->stream_index == AudioStream) {
					decoder = Audio;
					operation = "could not submit audio packet";
				}
				if (decoder != nullptr) {
					result = avcodec_send_packet(decoder, Packet);
					if (result < 0) {
						Log_FFmpeg_Error(operation, result);
						av_packet_unref(Packet);
						Failed = true;
						return(false);
					}
				}
				av_packet_unref(Packet);
			}
		}

		bool Flush_Decoders(void)
		{
			if (!VideoFlushSent) {
				int result = avcodec_send_packet(Video, nullptr);
				if (result >= 0 || result == AVERROR_EOF) {
					VideoFlushSent = true;
				} else if (result != AVERROR(EAGAIN)) {
					Log_FFmpeg_Error("could not flush video decoder", result);
					return(false);
				}
			}
			if (Audio != nullptr && !AudioFlushSent) {
				int result = avcodec_send_packet(Audio, nullptr);
				if (result >= 0 || result == AVERROR_EOF) {
					AudioFlushSent = true;
				} else if (result != AVERROR(EAGAIN)) {
					Log_FFmpeg_Error("could not flush audio decoder", result);
					return(false);
				}
			}
			if (Audio == nullptr) {
				AudioFinished = true;
			}
			return(true);
		}

		bool Drain_Decoders(void)
		{
			while (VideoFrames.size() < VideoQueueCapacity && !VideoFinished) {
				int result = avcodec_receive_frame(Video, VideoDecodedFrame);
				if (result == 0) {
					bool converted = Convert_Video_Frame();
					av_frame_unref(VideoDecodedFrame);
					if (!converted) {
						return(false);
					}
					continue;
				}
				if (result == AVERROR_EOF) {
					VideoFinished = true;
				} else if (result != AVERROR(EAGAIN)) {
					Log_FFmpeg_Error("could not decode video frame", result);
					return(false);
				}
				break;
			}

			while (Audio != nullptr && !AudioFinished) {
				int result = avcodec_receive_frame(Audio, AudioDecodedFrame);
				if (result == 0) {
					bool converted = Convert_Audio_Frame();
					av_frame_unref(AudioDecodedFrame);
					if (!converted) {
						return(false);
					}
					continue;
				}
				if (result == AVERROR_EOF) {
					if (!Flush_Resampler()) {
						return(false);
					}
					AudioFinished = true;
				} else if (result != AVERROR(EAGAIN)) {
					Log_FFmpeg_Error("could not decode audio frame", result);
					return(false);
				}
				break;
			}
			return(true);
		}

		bool Convert_Video_Frame(void)
		{
			if (VideoDecodedFrame->width != Width || VideoDecodedFrame->height != Height) {
				DebugString("FFmpeg movie decoder: video resolution changed during playback\n");
				return(false);
			}
			MovieFrame frame;
			double duration = 1.0 / FrameRate;

			AVStream *stream = Input.Get_Format()->streams[VideoStream];
			std::int64_t timestamp = VideoDecodedFrame->best_effort_timestamp;
			if (timestamp == AV_NOPTS_VALUE) {
				timestamp = VideoDecodedFrame->pts;
			}
			if (timestamp != AV_NOPTS_VALUE) {
				double pts = av_q2d(stream->time_base) * static_cast<double>(timestamp)
					- TimelineOrigin;
				if (!std::isfinite(pts) || pts - LastVideoTime > MaximumVideoGapSeconds) {
					DebugString("FFmpeg movie decoder: invalid video timestamp\n");
					return(false);
				}
				frame.PresentationTime = std::max(pts, LastVideoTime);
			} else {
				frame.PresentationTime = NextVideoTime;
			}
			if (VideoDecodedFrame->duration > 0) {
				double frameduration = av_q2d(stream->time_base)
					* static_cast<double>(VideoDecodedFrame->duration);
				if (std::isfinite(frameduration) && frameduration > 0.0
					&& frameduration <= MaximumVideoGapSeconds) {
					duration = frameduration;
				}
			}
			frame.EndTime = frame.PresentationTime + duration;
			LastVideoTime = frame.PresentationTime;
			NextVideoTime = frame.EndTime;

			AVPixelFormat targetformat;
			if (OutputFormat == MOVIE_PIXEL_BGRA8888) {
				targetformat = AV_PIX_FMT_BGRA;
			} else {
				targetformat = AV_PIX_FMT_RGB565LE;
			}
			frame.Pixels.resize(static_cast<std::size_t>(Pitch) * Height);

			AVPixelFormat sourceformat = static_cast<AVPixelFormat>(VideoDecodedFrame->format);
			Scaler = sws_getCachedContext(Scaler, Width, Height, sourceformat, Width, Height,
				targetformat, SWS_BILINEAR, nullptr, nullptr, nullptr);
			if (Scaler == nullptr) {
				return(false);
			}
			int const *coefficients = sws_getCoefficients(
				Swscale_Color_Space(VideoDecodedFrame->colorspace));
			if (sws_setColorspaceDetails(Scaler, coefficients,
				VideoDecodedFrame->color_range == AVCOL_RANGE_JPEG, coefficients, 1,
				0, 1 << 16, 1 << 16) < 0) {
				return(false);
			}
			uint8_t *outputs[] = {
				frame.Pixels.data(), nullptr, nullptr, nullptr,
			};
			int strides[] = {Pitch, 0, 0, 0};
			if (sws_scale(Scaler, VideoDecodedFrame->data, VideoDecodedFrame->linesize,
				0, Height, outputs, strides) != Height) {
				return(false);
			}
			VideoFrames.push_back(std::move(frame));
			return(true);
		}

		bool Ensure_Resampler(void)
		{
			if (Resampler != nullptr) {
				return(true);
			}
			if (swr_alloc_set_opts2(&Resampler, &AudioDecodedFrame->ch_layout, AV_SAMPLE_FMT_S16,
					AudioFormat.SampleRate, &AudioDecodedFrame->ch_layout,
					static_cast<AVSampleFormat>(AudioDecodedFrame->format),
					AudioDecodedFrame->sample_rate, 0, nullptr) < 0
				|| swr_init(Resampler) < 0) {
				return(false);
			}
			return(true);
		}

		bool Convert_Audio_Frame(void)
		{
			if (!Ensure_Resampler()) {
				return(false);
			}
			int capacity = swr_get_out_samples(Resampler, AudioDecodedFrame->nb_samples);
			if (capacity < 0) {
				return(false);
			}

			std::vector<std::int16_t> samples(
				static_cast<std::size_t>(capacity) * AudioFormat.Channels);
			uint8_t *output[] = {reinterpret_cast<uint8_t *>(samples.data())};
			int produced = swr_convert(Resampler, output, capacity,
				AudioDecodedFrame->extended_data,
				AudioDecodedFrame->nb_samples);
			if (produced < 0) {
				return(false);
			}
			samples.resize(static_cast<std::size_t>(produced) * AudioFormat.Channels);

			AVStream *stream = Input.Get_Format()->streams[AudioStream];
			std::int64_t timestamp = AudioDecodedFrame->best_effort_timestamp;
			if (timestamp == AV_NOPTS_VALUE) {
				timestamp = AudioDecodedFrame->pts;
			}
			std::int64_t correction = 0;
			if (timestamp != AV_NOPTS_VALUE) {
				double pts = av_q2d(stream->time_base) * static_cast<double>(timestamp)
					- TimelineOrigin;
				double target = pts * AudioFormat.SampleRate;
				if (!std::isfinite(target) || target >= 0x1p63) {
					DebugString("FFmpeg movie decoder: invalid audio timestamp\n");
					return(false);
				}
				std::int64_t targetframe = target <= 0.0
					? 0
					: static_cast<std::int64_t>(std::llround(target));
				correction = targetframe - AudioOutputFrames;
				std::int64_t tolerance = std::max(AudioFormat.SampleRate / 100, 1);
				if (std::abs(correction) <= tolerance) {
					correction = 0;
				}
			}

			if (correction > 0) {
				std::int64_t maximumgap = static_cast<std::int64_t>(AudioFormat.SampleRate)
					* MaximumAudioGapSeconds;
				if (correction > maximumgap) {
					DebugString("FFmpeg movie decoder: audio timestamp gap is too large\n");
					return(false);
				}
				std::size_t silenceframes = static_cast<std::size_t>(correction);
				samples.insert(samples.begin(),
					silenceframes * AudioFormat.Channels, 0);
			} else if (correction < 0) {
				std::size_t overlap = static_cast<std::size_t>(-correction);
				std::size_t available = samples.size() / AudioFormat.Channels;
				overlap = std::min(overlap, available);
				samples.erase(samples.begin(),
					samples.begin() + overlap * AudioFormat.Channels);
			}
			AudioOutputFrames += samples.size() / AudioFormat.Channels;
			Queue_Audio(std::move(samples));
			return(true);
		}

		bool Flush_Resampler(void)
		{
			if (Resampler == nullptr) {
				return(true);
			}
			int capacity = swr_get_out_samples(Resampler, 0);
			if (capacity <= 0) {
				return(capacity == 0);
			}
			std::vector<std::int16_t> samples(
				static_cast<std::size_t>(capacity) * AudioFormat.Channels);
			uint8_t *output[] = {reinterpret_cast<uint8_t *>(samples.data())};
			int produced = swr_convert(Resampler, output, capacity, nullptr, 0);
			if (produced < 0) {
				return(false);
			}
			samples.resize(static_cast<std::size_t>(produced) * AudioFormat.Channels);
			AudioOutputFrames += produced;
			Queue_Audio(std::move(samples));
			return(true);
		}

		void Queue_Audio(std::vector<std::int16_t> &&samples)
		{
			if (samples.empty()) {
				return;
			}
			if (AudioSamples.empty()) {
				AudioSamples = std::move(samples);
			} else {
				AudioSamples.insert(AudioSamples.end(), samples.begin(), samples.end());
			}
		}

		MoviePixelFormat OutputFormat;
		MovieInput Input;
		AVCodecContext *Video = nullptr;
		AVCodecContext *Audio = nullptr;
		AVFrame *VideoDecodedFrame = nullptr;
		AVFrame *AudioDecodedFrame = nullptr;
		AVPacket *Packet = nullptr;
		SwsContext *Scaler = nullptr;
		SwrContext *Resampler = nullptr;
		std::deque<MovieFrame> VideoFrames;
		std::vector<std::int16_t> AudioSamples;
		std::deque<PacketPointer> PendingVideoPackets;
		std::size_t PendingVideoBytes = 0;
		MovieAudioFormat AudioFormat;
		int VideoStream = -1;
		int AudioStream = -1;
		int Width = 0;
		int Height = 0;
		int Pitch = 0;
		double FrameRate = 15.0;
		double TimelineOrigin = 0.0;
		double LastVideoTime = 0.0;
		double NextVideoTime = 0.0;
		std::int64_t AudioOutputFrames = 0;
		bool DemuxFinished = false;
		bool VideoFlushSent = false;
		bool AudioFlushSent = false;
		bool VideoFinished = false;
		bool AudioFinished = false;
		bool Failed = false;
};


MovieDecoder::MovieDecoder(char const * filename, MoviePixelFormat format) :
	Impl(std::make_unique<Implementation>(filename, format))
{
}


MovieDecoder::~MovieDecoder(void) = default;


std::unique_ptr<MovieDecoder> MovieDecoder::Create(char const *filename,
	MoviePixelFormat format, bool decodeaudio)
{
	if (filename == nullptr) {
		return(nullptr);
	}
	std::unique_ptr<MovieDecoder> decoder(new MovieDecoder(filename, format));
	return(decoder->Impl->Open(decodeaudio) ? std::move(decoder) : nullptr);
}


bool MovieDecoder::Pump(bool prefetchaudio)
{
	return(Impl->Pump(prefetchaudio));
}


bool MovieDecoder::Has_Frame(void) const
{
	return(!Impl->VideoFrames.empty());
}


MovieFrame const & MovieDecoder::Frame(void) const
{
	return(Impl->VideoFrames.front());
}


MovieFrame MovieDecoder::Take_Frame(void)
{
	MovieFrame frame = std::move(Impl->VideoFrames.front());
	Impl->VideoFrames.pop_front();
	return(frame);
}


void MovieDecoder::Pop_Frame(void)
{
	Impl->VideoFrames.pop_front();
}


std::optional<double> MovieDecoder::Next_Frame_Time(void) const
{
	return(Impl->VideoFrames.size() > 1
		? std::optional<double>(Impl->VideoFrames[1].PresentationTime) : std::nullopt);
}


MovieAudioFormat MovieDecoder::Get_Audio_Format(void) const
{
	return(Impl->AudioFormat);
}


std::vector<std::int16_t> MovieDecoder::Take_Audio(void)
{
	return(std::move(Impl->AudioSamples));
}


bool MovieDecoder::Audio_Finished(void) const
{
	return(Impl->AudioFinished && Impl->AudioSamples.empty());
}


int MovieDecoder::Get_Width(void) const
{
	return(Impl->Width);
}


int MovieDecoder::Get_Height(void) const
{
	return(Impl->Height);
}


int MovieDecoder::Get_Pitch(void) const
{
	return(Impl->Pitch);
}
