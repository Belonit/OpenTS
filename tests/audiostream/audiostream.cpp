/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

// Exercises the stream producers and the feeder: an AUD streamed a chunk at a
// time matches its whole decode and loops without a seam, a WAV streams through
// miniaudio, pushed PCM converts and stops at the ring's edge, the feeder
// thread fills and releases streams, and a lost device is pumped and restarted
// while the game thread does nothing. Needs no game data.

#include "audio/audiodecode.h"
#include "audio/audiodevice.h"
#include "audio/audiomixer.h"
#include "audio/audiomovieclock.h"
#include "audio/audiostream.h"
#include "audio/audiovoice.h"

#include "doctest/doctest.h"

#include <chrono>
#include <cstring>
#include <thread>
#include <vector>

namespace {

unsigned int Seed = 777;


unsigned int Next_Random(void)
{
	Seed = Seed * 1103515245u + 12345u;
	return(Seed >> 8);
}


void Append(std::vector<uint8_t> & blob, void const * data, size_t size)
{
	uint8_t const * bytes = (uint8_t const *)data;
	blob.insert(blob.end(), bytes, bytes + size);
}


class MemoryByteSourceClass : public AudioByteSourceClass
{
	public:
		explicit MemoryByteSourceClass(std::vector<uint8_t> const & bytes) : Bytes(bytes), Cursor(0) {}

		size_t Read(void * buffer, size_t bytes) override
		{
			size_t available = Bytes.size() - Cursor;
			if (bytes > available) bytes = available;
			std::memcpy(buffer, Bytes.data() + Cursor, bytes);
			Cursor += bytes;
			return(bytes);
		}

		bool Seek(size_t position) override
		{
			if (position > Bytes.size()) return(false);
			Cursor = position;
			return(true);
		}

		size_t Position(void) const override { return(Cursor); }
		size_t Size(void) const override { return(Bytes.size()); }

	private:
		std::vector<uint8_t> Bytes;
		size_t Cursor;
};


std::unique_ptr<AudioByteSourceClass> Source(std::vector<uint8_t> const & bytes)
{
	return(std::unique_ptr<AudioByteSourceClass>(new MemoryByteSourceClass(bytes)));
}


std::vector<uint8_t> Make_Sos_File(unsigned chunks, unsigned rate)
{
	AUDHeaderType header;
	header.Rate = (uint16_t)rate;
	header.Size = 0;
	header.UncompSize = 0;
	header.Flags = AUD_FLAG_16BIT;
	header.Compression = AUD_CODEC_SOS;
	std::vector<uint8_t> blob;
	Append(blob, &header, sizeof(header));
	int32_t uncomp = 0;
	for (unsigned i = 0; i < chunks; i++) {
		unsigned comp = 200 + (Next_Random() % 300);
		comp -= comp % 4;
		AUDChunkHeaderType chunk;
		chunk.CompSize = (uint16_t)comp;
		chunk.UncompSize = (uint16_t)(comp * 4);
		chunk.Magic = AUD_CHUNK_MAGIC;
		Append(blob, &chunk, sizeof(chunk));
		for (unsigned b = 0; b < comp; b++) {
			uint8_t byte = (uint8_t)(Next_Random() & 0xFF);
			blob.push_back(byte);
		}
		uncomp += comp * 4;
	}
	int32_t size = (int32_t)(blob.size() - sizeof(header));
	std::memcpy(&blob[2], &size, sizeof(size));
	std::memcpy(&blob[6], &uncomp, sizeof(uncomp));
	return(blob);
}


std::vector<uint8_t> Make_Wav(unsigned frames, unsigned rate)
{
	std::vector<uint8_t> wav;
	uint32_t datasize = frames * 2;
	uint32_t riffsize = 36 + datasize;
	Append(wav, "RIFF", 4);
	Append(wav, &riffsize, 4);
	Append(wav, "WAVEfmt ", 8);
	uint32_t fmtsize = 16;
	uint16_t format = 1;
	uint16_t channels = 1;
	uint32_t byterate = rate * 2;
	uint16_t align = 2;
	uint16_t bits = 16;
	Append(wav, &fmtsize, 4);
	Append(wav, &format, 2);
	Append(wav, &channels, 2);
	Append(wav, &rate, 4);
	Append(wav, &byterate, 4);
	Append(wav, &align, 2);
	Append(wav, &bits, 2);
	Append(wav, "data", 4);
	Append(wav, &datasize, 4);
	for (unsigned i = 0; i < frames; i++) {
		int16_t sample = (int16_t)(i * 37);
		Append(wav, &sample, sizeof(sample));
	}
	return(wav);
}


// Drains a ring into a vector, in pieces, until the producer says it is done or
// stops making progress.
std::vector<int16_t> Drain(AudioFileStreamProducerClass & producer, AudioStreamClass & stream, unsigned maxframes)
{
	std::vector<int16_t> out;
	std::vector<int16_t> piece(1000 * stream.Channels());
	bool more = true;
	int stalls = 0;
	while (out.size() / stream.Channels() < maxframes && stalls < 100) {
		if (more) {
			more = producer.Fill(stream);
		}
		unsigned got = stream.Ring.Read(piece.data(), 1000);
		if (got == 0) {
			if (!more) break;
			stalls++;
			continue;
		}
		stalls = 0;
		out.insert(out.end(), piece.begin(), piece.begin() + (size_t)got * stream.Channels());
	}
	return(out);
}


// An AUD of random SOS chunks, with its whole decode for comparison.
struct AudFixture
{
	std::vector<uint8_t> file;
	std::vector<int16_t> whole;
	unsigned frames = 0;

	explicit AudFixture(unsigned chunks = 30)
	{
		Seed = 777;
		file = Make_Sos_File(chunks, 22050);
		AUDHeaderType header;
		REQUIRE(Aud_Read_Header(file.data(), file.size(), header));
		whole.resize(Aud_Frame_Capacity(header));
		AudioPcmFormat format;
		frames = Aud_Decode(file.data(), file.size(), whole.data(), (unsigned)whole.size(), format);
		whole.resize(frames);
	}
};


struct LongAudFixture : AudFixture
{
	LongAudFixture(void) : AudFixture(80) {}
};


AudioCommand Play_Stream(AudioStreamClass * stream)
{
	AudioCommand play;
	std::memset(&play, 0, sizeof(play));
	play.Type = AudioCommandType::PLAY_STREAM;
	play.Group = AUDIO_GROUP_MOVIE;
	play.Slot = 2;
	play.Generation = 1;
	play.A = 1.0f;
	play.C = 1.0f;
	play.Ptr = stream;
	return(play);
}


// A movie stream of constant PCM playing through the null device.
struct DeviceFixture
{
	AudioMixerClass mixer;
	NullAudioDeviceClass device;
	AudioStreamClass stream;
	AudioPushStreamProducerClass producer;

	explicit DeviceFixture(unsigned frames) :
		device(480, 3)
	{
		REQUIRE(mixer.Init(48000, 2));
		REQUIRE(device.Open(48000, 2, AudioMixerClass::Render_Callback, &mixer));
		REQUIRE(device.Start());

		stream.Init(96000, 1, 48000);
		producer.Open(stream);
		std::vector<int16_t> pcm(frames, 1000);
		producer.Push(pcm.data(), (unsigned)(pcm.size() * sizeof(int16_t)), false);
		REQUIRE(mixer.Allocate_Voice(2));
		REQUIRE(mixer.Push(Play_Stream(&stream)));
	}
};

}


TEST_CASE_FIXTURE(AudFixture, "an AUD producer reports its format and needs a ring no larger than the stream's")
{
	AudioStreamClass stream;
	REQUIRE(stream.Init(16000, 1, 22050));
	AudioFileStreamProducerClass producer;
	REQUIRE(producer.Open(Source(file), false));
	CHECK(producer.Rate() == 22050u);
	CHECK(producer.Channels() == 1u);
	CHECK(producer.Min_Ring_Frames() > 0u);
	CHECK(producer.Min_Ring_Frames() <= stream.Ring.Capacity());
}


// A ring smaller than one chunk cannot be fed and is reported as ended, not spun on.
TEST_CASE_FIXTURE(AudFixture, "a ring too small for a chunk ends the producer")
{
	AudioStreamClass tiny;
	tiny.Init(100, 1, 22050);
	AudioFileStreamProducerClass producer;
	producer.Open(Source(file), false);
	CHECK_FALSE(producer.Fill(tiny));
}


TEST_CASE_FIXTURE(AudFixture, "a streamed AUD equals its whole decode, and a finished producer keeps reporting the end")
{
	AudioStreamClass stream;
	stream.Init(16000, 1, 22050);
	AudioFileStreamProducerClass producer;
	REQUIRE(producer.Open(Source(file), false));

	std::vector<int16_t> streamed = Drain(producer, stream, frames * 2);
	CHECK(streamed.size() == frames);
	CHECK(streamed == whole);
	CHECK_FALSE(producer.Fill(stream));
}


// Looping: the second pass repeats the first without a seam.
TEST_CASE_FIXTURE(AudFixture, "a looping AUD producer repeats the file from its start without a seam")
{
	AudioStreamClass stream;
	stream.Init(16000, 1, 22050);
	AudioFileStreamProducerClass looper;
	REQUIRE(looper.Open(Source(file), true));
	std::vector<int16_t> twice = Drain(looper, stream, frames * 2 + 500);
	REQUIRE(twice.size() >= frames * 2 + 500);
	CHECK_MESSAGE(std::memcmp(twice.data(), whole.data(), frames * sizeof(int16_t)) == 0, "the first pass matches");
	CHECK_MESSAGE(std::memcmp(twice.data() + frames, whole.data(), frames * sizeof(int16_t)) == 0, "the second pass repeats the first");
}


TEST_CASE("unknown data is refused by the file producer")
{
	std::vector<uint8_t> junk(50, 0x11);
	AudioFileStreamProducerClass bad;
	CHECK_FALSE(bad.Open(Source(junk), false));
}


TEST_CASE("a WAV streams through miniaudio in order and restarts from the top when it loops")
{
	std::vector<uint8_t> file = Make_Wav(9000, 44100);
	AudioStreamClass stream;
	stream.Init(8192, 1, 44100);

	AudioFileStreamProducerClass producer;
	REQUIRE(producer.Open(Source(file), true));
	CHECK(producer.Rate() == 44100u);
	CHECK(producer.Channels() == 1u);

	std::vector<int16_t> out = Drain(producer, stream, 9000 + 100);
	REQUIRE(out.size() >= 9100u);
	for (unsigned i = 0; i < 9000; i++) {
		INFO("frame ", i);
		CHECK(out[i] == (int16_t)(i * 37));
	}
	for (unsigned i = 0; i < 100; i++) {
		INFO("frame ", 9000 + i);
		CHECK(out[9000 + i] == (int16_t)(i * 37));
	}
}


TEST_CASE_FIXTURE(AudFixture, "a file's length is the frames an AUD decodes to, or the length a WAV header gives")
{
	AudioFileStreamProducerClass aud;
	aud.Open(Source(file), false);
	CHECK(aud.Length_Frames() == frames);

	std::vector<uint8_t> wav = Make_Wav(9000, 44100);
	AudioFileStreamProducerClass wavproducer;
	wavproducer.Open(Source(wav), false);
	CHECK(wavproducer.Length_Frames() == 9000u);
}


// Looping switched off before the end plays one pass; switched on, it keeps going.
TEST_CASE_FIXTURE(AudFixture, "looping can be switched off or on before the end")
{
	AudioStreamClass stream;
	stream.Init(16000, 1, 22050);

	AudioFileStreamProducerClass once;
	once.Open(Source(file), true);
	once.Set_Loop(false);
	CHECK_MESSAGE(Drain(once, stream, frames * 2).size() == frames, "switched off, the stream ends after one pass");

	stream.Reset();
	AudioFileStreamProducerClass again;
	again.Open(Source(file), false);
	again.Set_Loop(true);
	CHECK_MESSAGE(Drain(again, stream, frames * 2 + 500).size() >= frames * 2 + 500, "switched on, the stream starts over");
}


// An Ogg file's length is the position its last page records.
TEST_CASE("an Ogg length skips a last page that ends no packet, and data that is not Ogg has none")
{
	std::vector<uint8_t> ogg;
	auto page = [&ogg](uint64_t granule) {
		Append(ogg, "OggS", 4);
		ogg.push_back(0);
		ogg.push_back(0);
		Append(ogg, &granule, 8);
		for (int i = 0; i < 13; i++) {
			ogg.push_back(0);
		}
	};
	page(0);
	ogg.resize(ogg.size() + 5000, 0x55);
	page(123456);
	page(~(uint64_t)0);
	MemoryByteSourceClass oggsource(ogg);
	CHECK(Audio_Ogg_Length_Frames(oggsource) == 123456u);

	std::vector<uint8_t> wav = Make_Wav(9000, 44100);
	MemoryByteSourceClass wavsource(wav);
	CHECK(Audio_Ogg_Length_Frames(wavsource) == 0u);
}


// Looping switched on part way through a pass carries on into the next one.
TEST_CASE_FIXTURE(LongAudFixture, "looping switched on during a pass starts the file over")
{
	AudioStreamClass stream;
	stream.Init(8000, 1, 22050);
	AudioFileStreamProducerClass late;
	late.Open(Source(file), false);
	std::vector<int16_t> first = Drain(late, stream, frames / 2);
	late.Set_Loop(true);
	std::vector<int16_t> rest = Drain(late, stream, frames * 2);
	CHECK(first.size() + rest.size() >= frames * 2);
}


// Once the file has ended, switching looping on does not bring it back.
TEST_CASE_FIXTURE(LongAudFixture, "looping switched on after the end adds nothing")
{
	AudioStreamClass stream;
	stream.Init(8000, 1, 22050);
	AudioFileStreamProducerClass ended;
	ended.Open(Source(file), false);
	CHECK_MESSAGE(Drain(ended, stream, frames * 2).size() == frames, "a stream that does not loop plays one pass");
	ended.Set_Loop(true);
	CHECK_FALSE(ended.Fill(stream));
	CHECK(stream.Ring.Available_Read() == 0u);
}


// A looping file that yields no audio ends rather than being read again forever.
TEST_CASE_FIXTURE(LongAudFixture, "a looping file that yields no audio ends")
{
	SUBCASE("an AUD whose first chunk is damaged")
	{
		std::vector<uint8_t> broken = file;
		AUDChunkHeaderType chunk;
		std::memcpy(&chunk, &broken[sizeof(AUDHeaderType)], sizeof(chunk));
		chunk.Magic = 0;
		std::memcpy(&broken[sizeof(AUDHeaderType)], &chunk, sizeof(chunk));

		AudioStreamClass stream;
		stream.Init(8000, 1, 22050);
		AudioFileStreamProducerClass aud;
		REQUIRE_MESSAGE(aud.Open(Source(broken), true), "the damaged AUD opens");
		CHECK_FALSE(aud.Fill(stream));
	}

	SUBCASE("a WAV with no frames")
	{
		AudioStreamClass stream;
		stream.Init(16000, 1, 44100);
		std::vector<uint8_t> empty = Make_Wav(0, 44100);
		AudioFileStreamProducerClass wav;
		REQUIRE_MESSAGE(wav.Open(Source(empty), true), "the empty WAV opens");
		CHECK_FALSE(wav.Fill(stream));
	}
}


// Only the file's first stream sets its length, even when another stream's page is last.
TEST_CASE("an Ogg length ignores another stream's pages")
{
	std::vector<uint8_t> ogg;
	auto page = [&ogg](uint32_t serial, uint64_t granule) {
		Append(ogg, "OggS", 4);
		ogg.push_back(0);
		ogg.push_back(0);
		Append(ogg, &granule, 8);
		Append(ogg, &serial, 4);
		for (int i = 0; i < 9; i++) {
			ogg.push_back(0);
		}
	};
	page(7, 0);
	ogg.resize(ogg.size() + 5000, 0x55);
	page(7, 4321);
	page(8, 987654);
	MemoryByteSourceClass oggsource(ogg);
	CHECK(Audio_Ogg_Length_Frames(oggsource) == 4321u);
}


TEST_CASE("pushed PCM converts to frames and stops at the ring's edge, and the end can be marked")
{
	AudioStreamClass stream;
	stream.Init(100, 2, 22050);
	AudioPushStreamProducerClass producer;
	REQUIRE(producer.Open(stream));
	CHECK_MESSAGE(producer.Free_Frames() == 128u, "the free frames follow the ring");

	unsigned char eight[8] = {128, 128, 0, 255, 64, 192, 128, 128};
	CHECK_MESSAGE(producer.Push(eight, sizeof(eight), true) == 4u, "8-bit stereo bytes become frames");
	int16_t frames[8];
	REQUIRE(stream.Ring.Read(frames, 4) == 4u);
	CHECK_MESSAGE(frames[0] == 0, "8-bit samples are widened");
	CHECK(frames[2] == -32768);
	CHECK(frames[3] == 32512);
	CHECK(frames[4] == -16384);

	int16_t sixteen[6] = {1, 2, 3, 4, 5, 6};
	CHECK_MESSAGE(producer.Push(sixteen, sizeof(sixteen), false) == 3u, "16-bit bytes become frames");
	REQUIRE(stream.Ring.Read(frames, 3) == 3u);
	CHECK_MESSAGE(frames[0] == 1, "16-bit samples pass through");
	CHECK(frames[5] == 6);

	std::vector<int16_t> big(400, 9);
	CHECK(producer.Push(big.data(), (unsigned)(big.size() * sizeof(int16_t)), false) == 128u);
	CHECK(producer.Free_Frames() == 0u);

	CHECK_FALSE(stream.EndOfInput.load());
	producer.Mark_End();
	CHECK(stream.EndOfInput.load());
}


TEST_CASE("the feeder thread fills an attached stream, releases its slot on detach, and keeps running with nothing attached")
{
	AudioMixerClass mixer;
	REQUIRE(mixer.Init(48000, 2));
	AudioFeederClass feeder;
	CHECK_MESSAGE(!feeder.Start(), "the feeder cannot start before setup");
	REQUIRE(feeder.Setup(&mixer, nullptr));
	REQUIRE(feeder.Start());
	CHECK(feeder.Is_Running());

	Seed = 777;
	std::vector<uint8_t> file = Make_Sos_File(40, 22050);
	AudioStreamClass stream;
	stream.Init(20000, 1, 22050);
	AudioFileStreamProducerClass * producer = new AudioFileStreamProducerClass();
	REQUIRE(producer->Open(Source(file), false));

	CHECK(feeder.Attach(1, &stream, producer));
	CHECK_MESSAGE(!feeder.Attach(1, &stream, producer), "a busy slot refuses a second attach");
	CHECK(feeder.Is_Attached(1));

	auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(3);
	while (stream.Frames_Pushed() < 10000 && std::chrono::steady_clock::now() < deadline) {
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
	CHECK(stream.Frames_Pushed() >= 10000u);

	feeder.Detach(1);
	CHECK_FALSE(feeder.Is_Attached(1));
	delete producer;

	unsigned passes = feeder.Passes();
	std::this_thread::sleep_for(std::chrono::milliseconds(60));
	CHECK(feeder.Passes() > passes);
	feeder.Stop();
	CHECK_FALSE(feeder.Is_Running());
}


TEST_CASE("the feeder pumps the mixer by the wall clock while the device is lost, and restarts the device")
{
	DeviceFixture rig(48000);
	std::vector<float> out(4800 * 2);
	rig.device.Pump(out.data(), 4800);
	uint32_t before = rig.stream.Frames_Consumed();
	REQUIRE_MESSAGE(before > 0u, "the device consumes the stream while it runs");

	AudioFeederClass feeder;
	REQUIRE_MESSAGE(feeder.Setup(&rig.mixer, &rig.device), "the feeder is set up without its thread");
	feeder.Attach(0, &rig.stream, &rig.producer);
	rig.device.Set_Lost(true);
	CHECK(rig.device.Is_Lost());
	CHECK_FALSE(rig.device.Is_Running());

	// The game thread is doing nothing; only the feeder's passes advance things.
	feeder.Service();
	CHECK_MESSAGE(feeder.Is_Recovering(), "the feeder notices the loss");
	std::this_thread::sleep_for(std::chrono::milliseconds(60));
	feeder.Service();
	uint32_t during = rig.stream.Frames_Consumed();
	CHECK(during > before);
	CHECK(during - before >= 48000u * 50 / 1000);
	CHECK(during - before <= 48000u * 200 / 1000);

	auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(AUDIO_DEVICE_RETRY_MS + 500);
	while (!rig.device.Is_Running() && std::chrono::steady_clock::now() < deadline) {
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		feeder.Service();
	}
	CHECK(rig.device.Is_Running());
	feeder.Service();
	CHECK_MESSAGE(!feeder.Is_Recovering(), "recovery ends once the device runs");
	feeder.Detach(0);
}


// The hardware stays away long enough for the feeder to close the device and
// fail to reopen it; the feeder must keep pumping and keep trying until the
// hardware is back.
TEST_CASE("the feeder keeps pumping with an unplugged device closed and reopens it once it is back")
{
	DeviceFixture rig(96000);
	AudioFeederClass feeder;
	REQUIRE(feeder.Setup(&rig.mixer, &rig.device));
	feeder.Set_Recovery_Timing(20, 60);
	feeder.Attach(0, &rig.stream, &rig.producer);
	rig.device.Set_Unplugged(true);
	feeder.Service();
	CHECK(feeder.Is_Recovering());

	auto deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(1000);
	while (rig.device.Is_Open() && std::chrono::steady_clock::now() < deadline) {
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		feeder.Service();
	}
	CHECK_MESSAGE(!rig.device.Is_Open(), "the device is closed and could not be reopened");
	CHECK_FALSE(rig.device.Is_Lost());
	CHECK_FALSE(rig.device.Is_Running());
	CHECK_MESSAGE(feeder.Is_Recovering(), "recovery goes on while the device stays closed");

	uint32_t before = rig.stream.Frames_Consumed();
	std::this_thread::sleep_for(std::chrono::milliseconds(60));
	feeder.Service();
	CHECK(rig.stream.Frames_Consumed() > before);

	rig.device.Set_Unplugged(false);
	deadline = std::chrono::steady_clock::now() + std::chrono::milliseconds(1000);
	while (!rig.device.Is_Running() && std::chrono::steady_clock::now() < deadline) {
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		feeder.Service();
	}
	CHECK(rig.device.Is_Open());
	CHECK(rig.device.Is_Running());
	feeder.Service();
	CHECK_FALSE(feeder.Is_Recovering());

	std::vector<float> out(4800 * 2);
	before = rig.stream.Frames_Consumed();
	rig.device.Pump(out.data(), 4800);
	CHECK_MESSAGE(rig.stream.Frames_Consumed() > before, "the reopened device renders the mixer");
	feeder.Detach(0);
}


// The movie clock: ticks from frames heard, wall time while the sound stands
// still, repeated blocks taken off, and a pause left out of the count.
TEST_CASE("the movie clock ticks from the frames heard, carries on by wall time, and leaves a pause out")
{
	AudioMovieClockClass clock;
	unsigned const rate = 22050;
	unsigned const block = 4096;
	unsigned const latency = 441;
	clock.Reset(rate, block, latency, 60);

	CHECK_MESSAGE(clock.Ticks(0, 0, 100) == 0, "nothing heard yet");
	CHECK_MESSAGE(clock.Ticks(latency, 0, 101) == 0, "device latency is not heard");
	CHECK_MESSAGE(clock.Ticks(4410 + latency, 0, 105) == 12, "ticks follow the frames heard");
	CHECK_MESSAGE(clock.Ticks(4410 + latency, 0, 110) == 17, "wall time carries the clock while the sound stands still");
	CHECK_MESSAGE(clock.Ticks(4410 + latency, 0, 108) == 17, "the wall clock never runs the count backwards");
	CHECK_MESSAGE(clock.Ticks(8820 + latency, 0, 120) == 24, "a new position resets the count from the sound");
	CHECK_MESSAGE(clock.Ticks(8820 + latency, 1, 130) == 34, "a repeated block is taken off, so the sound seems to stand still");
	CHECK_MESSAGE(clock.Ticks(13230 + latency, 1, 140) == 24, "later frames minus the repeated block");

	clock.Pause();
	CHECK(clock.Is_Paused());
	CHECK_MESSAGE(clock.Ticks(20000, 1, 200) == 24, "a paused clock holds");
	clock.Resume(260);
	CHECK_MESSAGE(clock.Ticks(13230 + latency, 1, 265) == 29, "the pause is left out of the count");
	CHECK_MESSAGE(clock.Pause_Adjust() == 120, "the pause adjust is the wall time lost");
	clock.Resume(300);
	CHECK_MESSAGE(clock.Ticks(13230 + latency, 1, 270) == 34, "a resume while running changes nothing");
}
