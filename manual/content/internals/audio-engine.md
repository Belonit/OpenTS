---
title: Audio engine
summary: A fixed voice pool rendered on the device thread and fed by the game and feeder threads.
category: architecture
source_files:
  - code/audio/audiodefs.hh
  - code/audio/audiohandle.h
  - code/audio/audioring.h
  - code/audio/audiolevel.cpp
  - code/audio/audiodecode.cpp
  - code/audio/audiosample.cpp
  - code/audio/audiomixer.cpp
  - code/audio/audiostream.cpp
  - code/audio/audiodevice.h
  - code/audio/audiodevice_ma.cpp
  - code/audio/audioevent.cpp
  - code/audio/audioengine.cpp
  - code/audio/audiomovie.cpp
  - code/vocini.cpp
  - code/voc.cpp
  - code/vox.cpp
  - code/theme.cpp
---

The audio engine lives under `code/audio/`, and one global, `AudioEngine`, owns it. Three threads use it:

- The game thread calls every public member.
- The device thread runs the mixer's render callback.
- The feeder thread fills stream rings and recovers a lost device.

The render callback never allocates memory, logs, opens a file, or waits on a lock. If another thread is already rendering when the callback runs, the callback writes silence for that period.

## Layers

### Device

The device layer is the `AudioDeviceClass` interface, and the game uses its miniaudio implementation. Another library could replace the output device behind that interface without changes to the mixer. The mixer's resampler and the decoders still come from miniaudio. OpenTS builds miniaudio with only its device layer, its resampler and its WAV, Ogg Vorbis, FLAC and MP3 decoders; its engine, node graph and resource manager are compiled out.

The device opens as 48 kHz stereo 32-bit float and requests three periods of 10 ms. The backend may choose a different period size or count. miniaudio converts that output to the hardware's own rate, so the mixer runs at 48 kHz on every device, including after the output moves to another device. miniaudio's null backend is excluded: a machine with no sound hardware gets no device, and the game plays no sound.

When the device stops without the engine stopping it, the feeder thread renders the mixer into a scratch buffer at wall-clock rate, so voices still finish and the movie clock keeps advancing. The feeder tries to restart the device every two seconds. If the device still has not restarted ten seconds after it stopped, the feeder closes and reopens it, and it repeats the reopen every ten seconds until the device runs.

### Mixer

The mixer has 64 voices. A voice plays either a sequence of decoded clips (attack, body loop and decay) or a stream ring. The voice resamples its source to 48 kHz, adjusted by its pitch. A source is never read faster than four times the output rate, so pitch is capped for high-rate sources.

A voice's loudness is the product of six ramped levels: its own, its own pause level, its group's, its group's duck level, the master level, and the focus-pause level. That product passes through one loudness curve, gain = level^(5/3), which is the volume mapping of the original DirectSound driver. Voices add into the output, and output samples above 0.9 in magnitude are soft-clipped.

The game thread changes a voice only by pushing a command into a single-producer, single-consumer ring that holds 512 commands. The mixer applies the waiting commands at the start of each render. A command names its voice by slot and generation, so the mixer drops a command aimed at a voice that has since been reused. When the ring is full, a command pushed to it is lost:

- A start that plays at once fails and returns a null handle. If the sound type has `QUEUE` in [`Control=`](/keys/control/), the start keeps its handle and is retried for up to two seconds.
- A sound with `PREDELAY` returns its handle before it pushes anything. If its push fails when the silence ends, the sound ends without playing.
- Any other change, such as a volume change or a stop, is dropped.

A voice moves from allocated to playing and can pause and resume. It becomes done when it plays to its end, and passes through stopping first when it is stopped or ended early. A voice whose start the mixer rejects goes from allocated straight to done. The game thread owns a voice while it is free, allocated or done, and the device thread owns it while it is playing, paused or stopping. The game thread frees a voice only when it is done, or when it was allocated and never started.

A pause or a resume can fade over a given time; a voice fading toward a pause still counts as playing, and a resume during that fade turns it back. A stopped voice is done once its stop fade ends, even if a volume change is still running under it. A second stop can make that fade end sooner but never later, and stopping or ending a paused voice ends it at once without sound. Ending a voice during its fade toward a pause cancels the pause, and the voice finishes.

### Sample cache

The sample cache holds decoded 16-bit PCM. A named sample is keyed by its name, ignoring case. An AUD already in memory is keyed by its address and a hash of its contents, so a buffer refilled with a different sample does not replay the old one.

A sample is pinned while a voice plays it, and a pinned sample is never evicted. A loop with a `Delay=` unpins its samples during each silence, so they can be evicted then and loaded again for the next cycle. Whenever the cache holds more than 64 MB, unpinned samples are evicted, least recently used first. Pinned samples alone can keep the cache above 64 MB. A sample larger than 8 MB once decoded is refused.

### Streams

A stream is a ring of PCM that one producer writes and the mixer reads. The engine has eight stream slots, and opening a stream while all eight are in use fails. Stopping a stream closes its file at once, but its slot is not reused until its voice has finished reading the ring, which can take until focus returns when the mix is paused. The voice finishes after what was already read even if the stop command itself was lost.

Music and speech play as file streams. The feeder thread decodes them, an AUD one chunk at a time and any other format through miniaudio, into a ring that holds five seconds at the source rate. The game thread decodes the first block when the stream opens, so playback starts without waiting for the feeder.

The movie player takes a stream slot too and writes its PCM blocks into that ring. Its clock is the number of frames the mixer has consumed from the ring, less the audio still buffered in the device and any block the player wrote twice because it ran short of data. When the mixer stops consuming, for example after the sound track ends early, the clock runs on wall-clock time, so the picture does not freeze.

The feeder thread wakes every 16 ms and tops up every open file stream.

A file stream that loops starts again from the beginning of its file with no gap. Looping can be switched on or off while the stream plays and applies the next time the feeder reaches the end of the file, up to five seconds before that point is heard. Once the feeder has reached the end without looping, the stream ends regardless. A looping file that yields no audio after starting again ends as well.

The engine can also report how long a file would play without opening a stream: an AUD from its header, WAV, FLAC and MP3 from miniaudio, and Ogg Vorbis from the position recorded by the last page of its first stream. A file that states a length of more than a day counts as stating none.

### Event pool

The event pool holds 128 events. It builds a sound type's clip sequence, starts it on a voice, and then:

- enforces each type's [`Limit=`](/keys/limit/);
- keeps sound effects, meaning the SFX and system groups, to [`Channels=`](/keys/channels/) voices;
- when all those voices are in use, gives a new effect the voice of a weaker effect, meaning one with lower priority or one with equal priority that is more than 10% quieter. If no playing effect is weaker, the new effect does not start;
- plays a loop with a [`Delay=`](/keys/delay/) one cycle at a time, and releases the voice during each silence;
- answers queries and commands made through the handles the game holds.

Streams do not count toward `Channels=`, and their voices are never taken.

A handle is 4 bytes: an event slot and a generation stamp. A handle kept after its sound ends, or after its slot is reused, does nothing when called. `Is_Valid` and `Is_Playing` report false, `Type` reports null, and `Is_Finished` reports true. Streams and raw in-memory samples are events too, so one handle type covers everything the game plays.

## Game layer

- `VocClass` holds one sound type for each section listed in `[SoundList]` of SOUND.INI, and plays it as an event. The positional model and placed sounds are in `voc.cpp`, and the ambient-sound table is in `ambient.cpp`.
- Speech queues lines and plays each one as a stream.
- Music plays each track as a stream.
- The option sliders set the group levels. The sound effects slider sets both the SFX and movie groups, and the music and speech sliders set the music and speech groups.
- The radar movie ducks sound effects, speech and music to half their level while it plays, and restores them when it ends.
- Focus loss pauses all audio: the output fades out over 5 ms, and voices stop advancing until focus returns. The call only sets an atomic flag that the render callback reads, so any thread may deliver it.

## Invariants

- The game thread writes a clip sequence before the play command and does not change it while a voice plays it.
- Each stream ring has one writing thread and one reading thread.
- Random choices for pitch, volume, clip selection and delay use the non-critical random generator, so audio never advances the simulation's random sequence.
- If no device opens at startup, the engine stays silent for the session. Calls that play, stop or change a sound do nothing, and play calls return a null handle.
- Group and master levels set before startup opens the device are kept and applied when it opens.
