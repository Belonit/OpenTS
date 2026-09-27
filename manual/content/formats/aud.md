---
format_id: aud
title: AUD audio
summary: Westwood's audio format, which holds the game's sound effects, speech and music.
kind: binary
extensions:
  - .AUD
role: audio
related:
  - { type: format, id: mix }
source_files:
  - code/audio/audiodecode.h
  - code/audio/audiodecode.cpp
  - code/audio/audiosample.cpp
  - code/audio/audiostream.cpp
  - code/voc.cpp
  - code/theme.cpp
  - code/vox.cpp
---

The game finds every `.AUD` file by name through the normal file search. A loose file in the game directory replaces a member of a mounted archive with the same name; [MIX archives](/formats/mix/) covers which archives are mounted.

## How a sample is found

Sound effects, music and speech name their files differently:

- A sound effect's samples are named in [SOUND.INI](/formats/sound-ini/) without an extension. The game tries `.WAV`, `.OGG`, `.FLAC` and `.MP3` under each name before `.AUD`, and plays the first file that decodes. [Sound effects](/systems/sound-effects/#samples) covers the size limit and how long a decoded sample stays in memory.
- A music track plays from the `.AUD` file named after its [THEME.INI](/formats/theme-ini/) ID, and a [speech](/systems/eva-speech/) line from the `.AUD` file with its name. The game reads these files while they play and keeps nothing of them in memory afterward. [Music](/systems/music/) covers what happens when a track's file is missing.

A file with the `.AUD` extension that holds WAV, OGG, FLAC or MP3 data also plays, as a sound effect, music track or speech line. The game reads such a file by its content when it does not start with a valid AUD header.

## When sound effects and music are silent

A sound effect starts only when all of these hold:

- the sound effect volume option is above zero, except for the test beep the voice volume control plays outside a game;
- the volume the sound is played at, after any fade with distance, is above zero;
- the game was not started with the [quiet launch option](/using/command-line/quiet/);
- its SOUND.INI entry names at least one sample;
- an audio device is available.

A music track starts only when all of these hold:

- an audio device is available;
- the game was not started with the quiet launch option;
- the music volume is above zero.

## File structure

An AUD file is a 12-byte header followed by the sample data. Numbers are stored low byte first.

| Offset | Bytes | Holds |
| --- | --- | --- |
| 0 | 2 | Playback rate in hertz |
| 2 | 4 | Size of the data after the header, in bytes |
| 6 | 4 | Size of the data once uncompressed, in bytes |
| 10 | 1 | Flags: `1` for stereo, `2` for 16-bit samples |
| 11 | 1 | Compression code |

The file does not play if any of these holds:

- the rate is `0`;
- the data size is `0` or less, or larger than the rest of the file;
- a flag other than stereo and 16-bit is set;
- the compression code is not one of the three below;
- the compression code is `1` and the 16-bit flag is set.

Any other rate plays as written, except that a rate above 20000 and below 24000 hertz plays at 22050. Mono and stereo samples both play, at either bit depth.

| Code | Compression |
| --- | --- |
| `0` | None. 8-bit samples are unsigned and 16-bit samples are signed; stereo samples alternate left and right. |
| `1` | Westwood delta compression, for 8-bit samples only |
| `99` | ADPCM, the compression the shipped files use |

With code `1` or `99`, the data is a series of blocks. Each block starts with an 8-byte header: its compressed size in 2 bytes, its uncompressed size in 2 bytes, and the marker `0x0000DEAF` in 4 bytes. A block whose two sizes are equal is stored uncompressed.

Keep each block within these limits:

- The uncompressed size is at most 8392 bytes and holds a whole number of samples for every channel. The sample ends before a block that breaks this.
- The compressed size is at most 2098 bytes. Music and speech end before a larger block. A sound effect with code `99` also ends there, unless that block is stored uncompressed.

The sample also ends before a block without the marker, and before a code `1` block that does not decode to its uncompressed size. The blocks before it still play.

Set the header's uncompressed size to the full decoded size in a code `1` file. A sound effect ends before the first block that would take it past that size. A value of `0` counts as four times the data size.
