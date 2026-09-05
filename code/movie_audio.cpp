/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "always.h"

#include "movie_audio.h"

#include "dbgprint.h"
#include "dsaudio.h"

#include <algorithm>
#include <cstring>
#include <limits>
#include <utility>


namespace {

constexpr int BufferMilliseconds = 2000;


class AudioMutexGuard
{
	public:
		AudioMutexGuard(void) : Locked(Audio.Lock_Mutex()) {}
		~AudioMutexGuard(void)
		{
			if (Locked) {
				Audio.Unlock_Mutex();
			}
		}

		explicit operator bool(void) const { return(Locked); }

	private:
		bool Locked;
};

} // namespace


class MovieAudioPlayback::Implementation
{
	public:
		Implementation(MovieAudioFormat format, int volume)
		{
			if (!Audio_Available() || !format) {
				Completed = true;
				return;
			}
			std::uint64_t channels = static_cast<std::uint64_t>(format.Channels);
			std::uint64_t blockalign = channels * sizeof(std::int16_t);
			std::uint64_t bytespersecond = static_cast<std::uint64_t>(format.SampleRate) * blockalign;
			std::uint64_t bufferbytes = bytespersecond * BufferMilliseconds / 1000;
			if (channels > std::numeric_limits<WORD>::max() / sizeof(std::int16_t)
				|| bytespersecond > std::numeric_limits<DWORD>::max()
				|| bufferbytes < blockalign || bufferbytes > std::numeric_limits<DWORD>::max()) {
				Completed = true;
				return;
			}
			bufferbytes -= bufferbytes % blockalign;

			WAVEFORMATEX wave = {};
			wave.wFormatTag = WAVE_FORMAT_PCM;
			wave.nChannels = static_cast<WORD>(format.Channels);
			wave.nSamplesPerSec = format.SampleRate;
			wave.wBitsPerSample = 16;
			wave.nBlockAlign = static_cast<WORD>(blockalign);
			wave.nAvgBytesPerSec = static_cast<DWORD>(bytespersecond);

			BytesPerSecond = wave.nAvgBytesPerSec;
			BlockAlign = wave.nBlockAlign;
			BufferBytes = static_cast<DWORD>(bufferbytes);

			DSBUFFERDESC description = {};
			description.dwSize = sizeof(description);
			description.dwFlags = DSBCAPS_CTRLVOLUME | DSBCAPS_GETCURRENTPOSITION2;
			description.dwBufferBytes = BufferBytes;
			description.lpwfxFormat = &wave;

			{
				AudioMutexGuard guard;
				LPDIRECTSOUND directsound = Direct_Sound_Object();
				if (!guard || directsound == nullptr) {
					Buffer = nullptr;
					Completed = true;
					return;
				}
				HRESULT result = directsound->CreateSoundBuffer(&description, &Buffer, nullptr);
				if (FAILED(result)) {
					DebugString("Movie audio: could not create DirectSound buffer (0x%08lX)\n",
						static_cast<unsigned long>(result));
					Buffer = nullptr;
					Completed = true;
					return;
				}
			}

			void *first = nullptr;
			void *second = nullptr;
			DWORD firstsize = 0;
			DWORD secondsize = 0;
			if (!Lock_Buffer(0, BufferBytes, &first, &firstsize, &second, &secondsize,
				"could not initialize DirectSound buffer")) {
				Buffer->Release();
				Buffer = nullptr;
				Completed = true;
				return;
			}
			std::memset(first, 0, firstsize);
			if (second != nullptr) {
				std::memset(second, 0, secondsize);
			}
			if (!Check(Buffer->Unlock(first, firstsize, second, secondsize),
				"could not unlock DirectSound buffer")) {
				Buffer->Release();
				Buffer = nullptr;
				Completed = true;
				return;
			}
			Set_Volume(volume);
		}

		~Implementation(void)
		{
			if (Buffer != nullptr) {
				Buffer->Stop();
				Buffer->Release();
			}
		}

		void Submit(std::vector<std::int16_t> &&samples)
		{
			if (Buffer == nullptr || samples.empty()) {
				return;
			}
			if (PendingOffset == PendingSamples.size()) {
				PendingSamples = std::move(samples);
				PendingOffset = 0;
				return;
			}
			if (PendingOffset != 0) {
				PendingSamples.erase(PendingSamples.begin(), PendingSamples.begin() + PendingOffset);
				PendingOffset = 0;
			}
			PendingSamples.insert(PendingSamples.end(),
				samples.begin(), samples.end());
		}

		void Finish(void)
		{
			SourceFinished = true;
			if (Buffer == nullptr) {
				Completed = true;
			}
		}

		bool Needs_Data(void) const
		{
			if (Buffer == nullptr || SourceFinished || BytesPerSecond == 0) {
				return(false);
			}
			std::uint64_t buffered = WriteAbsolute - std::min(PlayAbsolute, WriteAbsolute);
			buffered += (PendingSamples.size() - PendingOffset) * sizeof(PendingSamples[0]);
			return(buffered < BytesPerSecond / 2);
		}

		bool Start(double position)
		{
			if (Buffer == nullptr || Started || PendingOffset == PendingSamples.size()) {
				return(false);
			}
			std::uint64_t startbytes = static_cast<std::uint64_t>(
				std::max(position, 0.0) * BytesPerSecond);
			startbytes -= startbytes % BlockAlign;
			std::uint64_t startSamples = startbytes / sizeof(PendingSamples[0]);
			std::uint64_t available = PendingSamples.size() - PendingOffset;
			if (startSamples >= available) {
				if (SourceFinished) {
					PendingSamples.clear();
					PendingOffset = 0;
					Completed = true;
				}
				return(false);
			}
			PendingOffset += static_cast<std::size_t>(startSamples);
			PlayAbsolute = startbytes;
			SafeWriteAbsolute = startbytes;
			WriteAbsolute = startbytes;
			DWORD cursor = static_cast<DWORD>(startbytes % BufferBytes);
			if (!Run_Buffer_Operation([&]() { return(Buffer->SetCurrentPosition(cursor)); },
				"could not set initial playback position")) {
				return(false);
			}
			LastCursor = cursor;
			Write_Pending();
			if (RuntimeFailed) {
				return(false);
			}
			if (WriteAbsolute > PlayAbsolute) {
				if (!Run_Buffer_Operation([&]() { return(Buffer->Play(0, 0, DSBPLAY_LOOPING)); },
					"could not start playback")) {
					return(false);
				}
				Started = true;
				Paused = false;
			}
			return(Started);
		}

		void Update(void)
		{
			if (Buffer == nullptr || Completed) {
				return;
			}
			if (!Started) {
				if (SourceFinished && PendingOffset == PendingSamples.size()) {
					Completed = true;
				}
				return;
			}
			if (!Paused && !Buffering) {
				if (!Update_Cursor()) {
					return;
				}
				if (SafeWriteAbsolute >= WriteAbsolute
					&& PendingOffset < PendingSamples.size()) {
					if (!Run_Buffer_Operation([&]() { return(Buffer->Stop()); },
						"could not stop depleted buffer")) {
						return;
					}
					DWORD cursor = static_cast<DWORD>(WriteAbsolute % BufferBytes);
					if (!Run_Buffer_Operation([&]() { return(Buffer->SetCurrentPosition(cursor)); },
						"could not reset depleted buffer")) {
						return;
					}
					LastCursor = cursor;
					PlayAbsolute = WriteAbsolute;
					SafeWriteAbsolute = WriteAbsolute;
					Buffering = true;
				}
			}
			Write_Pending();
			if (RuntimeFailed) {
				return;
			}
			Write_Silence_After_Source();
			if (RuntimeFailed) {
				return;
			}
			if (Buffering && !Paused) {
				std::uint64_t queued = WriteAbsolute - PlayAbsolute;
				if (queued >= BytesPerSecond / 10 || SourceFinished) {
					if (!Run_Buffer_Operation([&]() { return(Buffer->Play(0, 0, DSBPLAY_LOOPING)); },
						"could not resume buffered playback")) {
						return;
					}
					Buffering = false;
				}
			}
			if (ContentEndKnown && PlayAbsolute >= ContentEndAbsolute) {
				if (!Run_Buffer_Operation([&]() { return(Buffer->Stop()); },
					"could not stop completed playback")) {
					return;
				}
				Completed = true;
			}
		}

		void Pause(void)
		{
			if (Buffer != nullptr && Started && !Paused && !Completed) {
				if (!Buffering) {
					if (!Update_Cursor()) {
						return;
					}
				}
				if (!Run_Buffer_Operation([&]() { return(Buffer->Stop()); },
					"could not pause playback")) {
					return;
				}
				Paused = true;
			}
		}

		void Resume(void)
		{
			if (Buffer != nullptr && Started && Paused && !Completed) {
				Paused = false;
				if (!Buffering) {
					Run_Buffer_Operation([&]() { return(Buffer->Play(0, 0, DSBPLAY_LOOPING)); },
						"could not resume playback");
				}
			}
		}

		bool Is_Finished(void) const
		{
			return(Completed || (SourceFinished && !Started
				&& PendingOffset == PendingSamples.size()));
		}

		bool Has_Failed(void) const
		{
			return(RuntimeFailed);
		}

		std::optional<double> Get_Playback_Position(void)
		{
			if (Buffer == nullptr || !Started || Completed || BytesPerSecond == 0) {
				return(std::nullopt);
			}
			if (!Paused && !Buffering && !Completed && !Update_Cursor()) {
				return(std::nullopt);
			}
			std::uint64_t end = ContentEndKnown ? ContentEndAbsolute : WriteAbsolute;
			return(static_cast<double>(std::min(PlayAbsolute, end))
				/ BytesPerSecond);
		}

	private:
		template <typename Operation>
		bool Run_Buffer_Operation(Operation operation, char const *description)
		{
			HRESULT result = operation();
			if (result == DSERR_BUFFERLOST) {
				if (!Restore_Buffer()) {
					return(false);
				}
				result = operation();
			}
			return(Check(result, description));
		}

		bool Restore_Buffer(void)
		{
			HRESULT result = Buffer->Restore();
			if (FAILED(result)) {
				Fail("could not restore lost DirectSound buffer", result);
				return(false);
			}

			void *first = nullptr;
			void *second = nullptr;
			DWORD firstsize = 0;
			DWORD secondsize = 0;
			result = Buffer->Lock(0, BufferBytes, &first, &firstsize, &second, &secondsize, 0);
			if (FAILED(result)) {
				Fail("could not clear restored DirectSound buffer", result);
				return(false);
			}
			std::memset(first, 0, firstsize);
			if (second != nullptr) {
				std::memset(second, 0, secondsize);
			}
			result = Buffer->Unlock(first, firstsize, second, secondsize);
			if (FAILED(result)) {
				Fail("could not unlock restored DirectSound buffer", result);
				return(false);
			}
			DWORD cursor = static_cast<DWORD>(PlayAbsolute % BufferBytes);
			if (!Check(Buffer->SetCurrentPosition(cursor),
				"could not restore playback position")) {
				return(false);
			}
			LastCursor = cursor;
			SafeWriteAbsolute = PlayAbsolute;
			if (Started && !Paused && !Buffering
				&& !Check(Buffer->Play(0, 0, DSBPLAY_LOOPING),
					"could not resume restored playback")) {
				return(false);
			}
			return(true);
		}

		bool Check(HRESULT result, char const *operation)
		{
			if (SUCCEEDED(result)) {
				return(true);
			}
			Fail(operation, result);
			return(false);
		}

		void Fail(char const *operation, HRESULT result)
		{
			DebugString("Movie audio: %s (0x%08lX)\n", operation,
				static_cast<unsigned long>(result));
			Buffer->Stop();
			RuntimeFailed = true;
			Completed = true;
		}

		bool Update_Cursor(void)
		{
			DWORD cursor = 0;
			DWORD writecursor = 0;
			if (!Run_Buffer_Operation([&]() { return(Buffer->GetCurrentPosition(&cursor, &writecursor)); },
				"could not query playback position")) {
				return(false);
			}
			cursor -= cursor % BlockAlign;
			writecursor -= writecursor % BlockAlign;
			DWORD delta = cursor >= LastCursor
				? cursor - LastCursor
				: BufferBytes - LastCursor + cursor;
			PlayAbsolute += delta;
			DWORD writedelta = writecursor >= cursor
				? writecursor - cursor
				: BufferBytes - cursor + writecursor;
			SafeWriteAbsolute = PlayAbsolute + writedelta;
			LastCursor = cursor;
			return(true);
		}

		bool Lock_Buffer(DWORD offset, DWORD count, void **first, DWORD *firstsize,
			void **second, DWORD *secondsize, char const *description)
		{
			return(Run_Buffer_Operation([&]() {
				return(Buffer->Lock(offset, count, first, firstsize, second, secondsize, 0));
			}, description));
		}

		void Write_Pending(void)
		{
			if (Buffer == nullptr || PendingOffset == PendingSamples.size()) {
				return;
			}
			if (PlayAbsolute > WriteAbsolute) {
				WriteAbsolute = PlayAbsolute;
			}

			std::uint64_t queued = WriteAbsolute - PlayAbsolute;
			std::uint64_t capacity = BufferBytes > queued + BlockAlign
				? BufferBytes - queued - BlockAlign : 0;
			std::uint64_t pending = (PendingSamples.size() - PendingOffset)
				* sizeof(PendingSamples[0]);
			DWORD count = static_cast<DWORD>(std::min(capacity, pending));
			count -= count % BlockAlign;
			if (count == 0) {
				return;
			}

			unsigned char const *source = reinterpret_cast<unsigned char const *>(
				PendingSamples.data() + PendingOffset);
			if (!Write_Buffer(source, count, "could not write streaming buffer")) {
				return;
			}
			PendingOffset += count / sizeof(PendingSamples[0]);
			if (PendingOffset == PendingSamples.size()) {
				PendingSamples.clear();
				PendingOffset = 0;
			}
		}

		void Write_Silence_After_Source(void)
		{
			if (!SourceFinished || PendingOffset != PendingSamples.size()) {
				return;
			}
			if (!ContentEndKnown) {
				ContentEndAbsolute = WriteAbsolute;
				ContentEndKnown = true;
			}
			if (PlayAbsolute > WriteAbsolute) {
				WriteAbsolute = PlayAbsolute;
			}
			std::uint64_t queued = WriteAbsolute - PlayAbsolute;
			std::uint64_t capacity = BufferBytes > queued + BlockAlign
				? BufferBytes - queued - BlockAlign : 0;
			DWORD count = static_cast<DWORD>(capacity - capacity % BlockAlign);
			if (count == 0) {
				return;
			}

			Write_Buffer(nullptr, count, "could not clear completed streaming buffer");
		}

		bool Write_Buffer(void const *source, DWORD count, char const *description)
		{
			void *first = nullptr;
			void *second = nullptr;
			DWORD firstsize = 0;
			DWORD secondsize = 0;
			DWORD offset = static_cast<DWORD>(WriteAbsolute % BufferBytes);
			if (!Lock_Buffer(offset, count, &first, &firstsize, &second, &secondsize, description)) {
				return(false);
			}
			if (source != nullptr) {
				std::memcpy(first, source, firstsize);
				if (second != nullptr) {
					std::memcpy(second, static_cast<unsigned char const *>(source) + firstsize, secondsize);
				}
			} else {
				std::memset(first, 0, firstsize);
				if (second != nullptr) {
					std::memset(second, 0, secondsize);
				}
			}
			if (!Check(Buffer->Unlock(first, firstsize, second, secondsize), description)) {
				return(false);
			}
			WriteAbsolute += count;
			return(true);
		}

		void Set_Volume(int volume)
		{
			if (Buffer != nullptr) {
				volume = std::clamp(volume, 0, 255);
				Run_Buffer_Operation([&]() {
					return(Buffer->SetVolume(Convert_HMI_To_Direct_Sound_Volume(volume)));
				}, "could not set movie volume");
			}
		}

		LPDIRECTSOUNDBUFFER Buffer = nullptr;
		std::vector<std::int16_t> PendingSamples;
		std::size_t PendingOffset = 0;
		DWORD BytesPerSecond = 0;
		DWORD BlockAlign = 0;
		DWORD BufferBytes = 0;
		DWORD LastCursor = 0;
		std::uint64_t PlayAbsolute = 0;
		std::uint64_t SafeWriteAbsolute = 0;
		std::uint64_t WriteAbsolute = 0;
		std::uint64_t ContentEndAbsolute = 0;
		bool Started = false;
		bool Paused = false;
		bool Buffering = false;
		bool SourceFinished = false;
		bool ContentEndKnown = false;
		bool Completed = false;
		bool RuntimeFailed = false;
};


MovieAudioPlayback::MovieAudioPlayback(MovieAudioFormat format, int volume) :
	Impl(std::make_unique<Implementation>(format, volume))
{
}


MovieAudioPlayback::~MovieAudioPlayback(void) = default;


void MovieAudioPlayback::Submit(std::vector<std::int16_t> &&samples)
{
	Impl->Submit(std::move(samples));
}


void MovieAudioPlayback::Finish(void)
{
	Impl->Finish();
}


bool MovieAudioPlayback::Needs_Data(void) const
{
	return(Impl->Needs_Data());
}


bool MovieAudioPlayback::Start(double position)
{
	return(Impl->Start(position));
}


void MovieAudioPlayback::Update(void)
{
	Impl->Update();
}


void MovieAudioPlayback::Pause(void)
{
	Impl->Pause();
}


void MovieAudioPlayback::Resume(void)
{
	Impl->Resume();
}


bool MovieAudioPlayback::Is_Finished(void) const
{
	return(Impl->Is_Finished());
}


bool MovieAudioPlayback::Has_Failed(void) const
{
	return(Impl->Has_Failed());
}


std::optional<double> MovieAudioPlayback::Get_Playback_Position(void)
{
	return(Impl->Get_Playback_Position());
}
