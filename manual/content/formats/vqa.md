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
  - { type: system, id: movie-playback }
source_files:
  - code/rules.cpp
  - thirdparty/ffmpeg/libavformat/westwood_vqa.c
  - thirdparty/ffmpeg/libavcodec/vqavideo.c
---

A `.VQA` is an IFF container holding vector-quantized video and, optionally, an audio track. The engine plays one either full screen, interrupting the mission, or a frame at a time inside the radar pane while the mission carries on. [Movie playback](/systems/movie-playback/) covers how the engine finds, decodes, and presents movie files.

## Registering a movie

Movie names come from the `[Movies]` section of the art layer: `ART.INI` first, then `ARTFS.INI` where that file is present. Each value is one movie name, without an extension. [Movie playback](/systems/movie-playback/#finding-and-opening-a-movie) resolves that name to a file.

```ini title="art.ini"
[Movies]
00=INTRO
01=GDI_M02
```

The section is walked in the order the file lists it in, and an entry key serves only to fetch its own value; nothing is taken from the key itself. A value that is empty registers nothing, and a name that is already registered is passed over, the comparison ignoring case. Only the first thirty-one characters of a value are kept.

One lookup answers both questions asked of a movie name: whether the registry already holds it, and which registered movie a setting means. That lookup returns nothing for `<none>` without searching at all, and both of its uses inherit that. Registration therefore never finds a `<none>` already present and adds every one it meets in either file, while a setting or a trigger action naming `<none>` selects no movie and is left at the value it already had. A name that was never registered is left at that value too.

Parts of the engine name a movie outright instead of going through the list — the startup sequence, the score screen and the mission screens all do. The normal extension search still applies, but the `[Movies]` section has no bearing on those requests.

## Container structure

Each chunk begins with a four-character identifier and a length, and the length is stored most significant byte first. A chunk of odd length is followed by a padding byte, so every chunk begins on an even boundary.

A VQA container starts with these identifiers:

- its first chunk is a `FORM`;
- the four characters recorded inside it are `WVQA`.

FFmpeg uses those identifiers to recognize the format. The 42-byte `VQHD` record starts at offset 20. Metadata chunks follow it until `FINF` and can appear in any order:

- `LINF`, `CINF`, and `PINF` are groups carrying the loop, codebook, and palette tables. Their header sub-chunks are `LINH`, `CINH`, and `PINH`.
- `MFCI` and `MSCI` carry tables of recurring frame and sound chunk types, headed by `MFCH` and `MSCH`. Each entry names a chunk identifier and the size of one buffered entry, and an `MFCI` entry also carries the period at which its chunk type recurs.
- `CLIP` contains a clipping rectangle.
- `FINF` contains the frame table and ends the metadata before the frame data.

Other chunks in this section are stepped over by their recorded length. Without `FINF`, the metadata section has no terminator.

The frames themselves follow in `VQFR` and `VQFK` containers holding codebook, palette, and vector-pointer chunks. A `VQFL` container supplies a codebook update for the following `VQFR` frame. A frame's sound is not inside its container: `SND0`, `SND1`, `SND2`, and `SN2J` sit beside the frame containers as chunks of the file.

## What the header supplies

The header is a fixed-length record read in one operation. The table sets each of the values used to construct the video and audio streams against what that value decides.

| Value                  | Effect                                                                                        |
| ---------------------- | --------------------------------------------------------------------------------------------- |
| Version                | Identifies format versions 1 through 3 and selects version-dependent `SND2` decoding behavior |
| Flags                  | Records format capabilities, including whether the file carries audio                         |
| Frames                 | Supplies the video frame count and duration                                                   |
| Image width and height | Set the decoded frame dimensions                                                              |
| Frame rate             | Sets the video timestamp interval and must be from 1 through 30                               |
| Single-color count     | Selects paletted color when nonzero and RGB555 otherwise                                      |
| Audio sample rate      | Sets the decoded audio rate                                                                   |
| Audio channels         | Selects mono or stereo output                                                                 |
| Audio sample width     | Selects the PCM representation where `SND0` is used                                           |

The record also carries the block dimensions, the codebook entry count, the number of frames per codebook, a drawing position, the largest frame and codebook sizes, an audio preload figure, a color mode, and the sample rate, channel count, and sample width of a second audio track.

The current decoder does not use the drawing position, color mode, or second audio track. A file carrying two tracks therefore plays its first one.
