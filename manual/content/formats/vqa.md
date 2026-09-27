---
format_id: vqa
title: VQA video
summary: Stores the full-motion video the engine plays full screen and in the radar pane.
kind: binary
extensions:
  - .VQA
role: video
related:
  - { type: format, id: mix }
source_files:
  - code/audio/audiomovie.cpp
  - code/movie.cpp
  - code/movies.cpp
  - code/rules.cpp
  - code/vqa.cpp
  - code/vqalib/buffer_.cpp
  - code/vqalib/drawer.cpp
  - code/vqalib/loader.cpp
  - code/vqalib/task.cpp
  - code/vqalib/vqafile.h
---

A `.VQA` file holds vector-quantized video and, optionally, a sound track, stored as a series of IFF chunks. The game plays a movie in one of three places:

- Full screen. The mission waits until the movie ends.
- In the radar pane. The mission goes on while the movie plays.
- In a graphical menu or the campaign map-selection screen.

## Registering a movie

Settings that name a movie, such as a scenario's [`Intro`](/keys/intro/) or a campaign's [`FinalMovie`](/keys/finalmovie/), accept only names registered in the `[Movies]` section of `ART.INI` or `ARTFS.INI`. Each value is one movie name without its extension. The game adds `.VQA` when it plays the movie.

```ini title="art.ini"
[Movies]
00=INTRO
01=GDI_M02
```

The game registers the entries of `ART.INI` first, then those of `ARTFS.INI` if that file exists, each in the order the file lists them. Only the values count, so any keys will do as long as they differ within a file. When two entries in one file share a key, only the later one is registered, at the later entry's place in the order. [`OPENTS.INI`](/formats/opents-ini/#the-files-it-reads) can name other files in place of these two.

- An empty value registers nothing.
- A name that is already registered, compared ignoring case, is skipped.
- A value longer than 31 characters is cut to its first 31.
- `<none>` is registered every time it appears, but no setting can select it.

Trigger actions and team missions store a movie as its position in this list, counting from 0. A skipped duplicate takes no position, and each `<none>` takes one.

A setting whose value is `<none>`, or a name that was never registered, is left unchanged.

These movies are named by file name, so `[Movies]` has no effect on them:

- The startup movies.
- The score screen movie.
- The main menu's intro movies.
- A campaign's [introduction movie](/systems/campaign-progression/#the-campaign-level-number), which plays before its first mission's briefing.
- The movies of the graphical menus and the map-selection screen.

:::danger[Keep movie names to 15 characters]
The game builds a registered movie's file name in a 20-byte buffer that holds the name, `.VQA` and a terminating byte. A name of 16 or more characters writes past the end of that buffer, by up to 16 bytes for a 31-character name, and overwrites the memory that follows it. The names the game ships with are eight characters or fewer.
:::

## Finding the file

Put movies in a [MIX archive](/formats/mix/). A loose `.VQA` file in a game folder passes the check that the movie exists, but the game reads movies only from archives, so a loose movie does not play. When a movie exists both loose and in an archive, the archived copy plays.

`SIZZLE1.VQA`, which the main menu's intro choice plays after the side's intro, is the one exception. The game reads it like any other file, so a loose copy plays and is used in place of an archived one.

:::caution[Keep movies out of cached archives]
A movie inside an archive the game caches at startup does not play. Among the patch and expansion archives, put movies in `PATCH.MIX` or an `EXPAND` archive, which are not cached, and not in `PCACHE.MIX` or an `ECACHE` archive, which are. [MIX archives](/formats/mix/#caching) lists which archives the game caches.
:::

## When a movie plays

A full-screen movie plays only when all of these hold, tested in this order:

1. The game is a campaign, or the launch file asked for movies. The menus count as a campaign, so the startup and main-menu movies pass. [Multiplayer movies](/systems/multiplayer-movies/) covers the launch file's key and how a movie ends in a game against other machines.
2. The file is found, loose or in an archive.
3. The movie opens. It must be an archive member, except `SIZZLE1.VQA`. Its chunks and header must be accepted as described below, and when the game has an audio device, its sound track must meet the limits in [Sound and picture](#sound-and-picture).
4. Its frame is at least 320 pixels wide or at least 200 pixels tall. A movie smaller than 320 by 200 in both directions is opened and then discarded.

A movie in the radar pane must pass the first three tests but not the size test. A movie shown by a graphical menu or the campaign map-selection screen needs to pass only the second and third.

A full-screen movie plays at its own size, centered on the screen, unless [`StretchMovies`](/keys/stretchmovies/) scales it to fit. The score screen movie always plays at its own size. A radar-pane movie is drawn from the pane's top-left corner.

## Container structure

Each chunk begins with a four-character ID and a four-byte length stored most significant byte first. A chunk of odd length is followed by one padding byte, so every chunk begins at an even offset.

The game accepts a file as a movie only when all of these hold, tested in this order:

1. The first chunk is a `FORM`.
2. That chunk's length is not zero.
3. The four characters that follow are `WVQA`.

Any other file does not open. After `WVQA`, the game reads the header chunks, in any order, until it reaches `FINF`:

| Chunk | What the game does with it |
| --- | --- |
| `VQHD` | Reads the header [described below](#what-the-header-supplies). The chunk must be exactly 42 bytes long, or the movie does not open. |
| `LINF`, `CINF`, `PINF` | Reads the loop, codebook and palette tables. Each must begin with its header chunk, `LINH`, `CINH` or `PINH`, or the movie does not open. The game plays every movie straight through once and never uses its loops. |
| `MFCI`, `MSCI` | Reads tables of extra chunk types for the player to buffer. Each must begin with its header chunk, `MFCH` or `MSCH`, or the movie does not open. The game loads the chunks these tables list, but they have no effect. |
| `CLIP` | Reads a clipping rectangle, which has no effect. |
| `FINF` | Reads the frame table and sets up playback from the header. The frames follow this chunk. |
| Any other chunk | Skips it. |

Put every header chunk before `FINF`. A header chunk after `FINF` is skipped with the frame data. A file without `FINF` does not open, because the game keeps reading chunks until a read fails.

A `VQFR` or `VQFK` chunk holds the codebook, palette and vector-pointer chunks of one frame. Any other chunk inside a `VQFR` or `VQFK` stops loading at that frame, so the movie ends early. The same codebook, palette and vector-pointer chunks can also sit directly between frames, and the frame then ends at its vector-pointer chunk. A `VQFL` chunk holds these chunks as loop data and does not end a frame.

The sound chunks `SND0`, `SND1`, `SND2` and `SN2J` sit between the frames. The game also reads the chunks that an `MFCI` or `MSCI` table lists. Any other chunk between frames is skipped.

## What the header supplies

The `VQHD` chunk holds a 42-byte header. Its values are stored least significant byte first, unlike chunk lengths.

| Offset | Size | Value | Meaning and effect |
| --- | --- | --- | --- |
| 0 | 2 | Version | Changes how some chunks are read; see the list below |
| 2 | 2 | Flags | Bit 0 declares a sound track. Without it the movie plays silent. |
| 4 | 2 | Frames | The number of frames played. The movie ends after this many. |
| 6 | 2 | Image width | The frame size in pixels, which decides placement, stretching and the size test |
| 8 | 2 | Image height | |
| 10 | 1 | Block width | The size of one vector-quantized block in pixels |
| 11 | 1 | Block height | |
| 12 | 1 | Frame rate | The playback speed in frames per second |
| 13 | 1 | Frames per codebook | How many frames share one codebook |
| 14 | 2 | Single-color count | Ignored. |
| 16 | 2 | Codebook entries | The number of entries in one codebook |
| 18 | 2 | Drawing position X | Ignored. The game places the movie itself. |
| 20 | 2 | Drawing position Y | |
| 22 | 2 | Largest frame size | The size of the largest frame, used to size the vector-pointer buffer. Its unit depends on the version. 0 uses a size worked out from the frame and block sizes. |
| 24 | 2 | Sample rate | The sound track's format |
| 26 | 1 | Channels | |
| 27 | 1 | Sample width | |
| 28 | 2 | Second track sample rate | Ignored. A movie with two sound tracks plays its first. |
| 30 | 1 | Second track channels | |
| 31 | 1 | Second track sample width | |
| 32 | 1 | Color mode | 1 or 4 marks a high-color movie, which is converted to the display's high-color format |
| 33 | 1 | Padding | |
| 34 | 4 | Largest codebook size | The stored size of the largest codebook. The movie does not open if this is larger than the codebook limit below. 0 uses the codebook limit. |
| 38 | 4 | Audio preload | The bytes of sound to load ahead of a seek point. The game never seeks within a movie, so this has no effect. |

The codebook limit is the number of codebook entries × the block width × the block height, plus 1. That sum is rounded up to a multiple of 4, then doubled for a high-color movie.

The version changes how the rest of the file is read:

- Below 2, the sound buffers are sized for 22050 hertz, 8-bit mono sound. The sound track still plays at the rate the audio values give.
- Below 3, compressed codebook, palette and vector-pointer chunks lack a terminating byte, and the game supplies it.
- From 3 up, the largest frame size is counted in 256-byte units, not bytes.

## Sound and picture

When the game has an audio device, a movie whose header declares a sound track opens only if the track has a sample rate above 0, one or two channels, and 8-bit or 16-bit samples. A movie that fails these limits does not play.

Only one movie with sound can be open at a time. While one is open, including a radar-pane movie that is still waiting its turn, another movie with sound does not open and so does not play.

The picture follows the sound. The game draws the frame that matches the sound heard so far. Sound still waiting in the output device does not count. The picture and sound therefore stay in step through an audio device change or a stall in the game. If the game falls behind and feeds a block of sound twice, the repeated block does not count, so the picture waits for the sound.

While the sound is not advancing, such as after the sound track ends before the picture or while the audio device is being recovered, the picture is timed by real time. Time spent paused does not count. A movie without sound, or one played with no audio device, is timed by real time throughout.

A `SND1` chunk uses Westwood delta compression and is decoded with the same checks as an [AUD](/formats/aud/) file. A chunk that does not decode to its stated size plays as silence.
