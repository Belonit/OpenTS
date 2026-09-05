---
title: Movie playback
summary: Finds, decodes, schedules, and presents full-screen and embedded movies.
category: rendering-presentation
keys:
  - SoundVolume
  - StretchMovies
related:
  - type: format
    id: vqa
  - type: format
    id: mix
---

Movie filenames keep the engine's existing `.VQA` convention, but FFmpeg identifies their container and codecs from the file contents. The same player handles full-screen movies and movies in the radar pane.

## Supported data

The bundled FFmpeg build accepts these combinations:

| Container     | Video      | Audio                                                                       |
| ------------- | ---------- | --------------------------------------------------------------------------- |
| Westwood VQA  | VQA        | Westwood IMA ADPCM, Westwood SND1, unsigned 8-bit PCM, or signed 16-bit PCM |
| Bink 1        | Bink Video | Bink Audio DCT or RDFT                                                      |
| WebM/Matroska | VP8 or VP9 | Opus or Vorbis                                                              |

No other demuxers or decoders are included. The build also excludes encoders, network protocols, command-line programs, device input, and filters. A Bink 1 or Matroska/WebM replacement must retain the `.VQA` filename expected by the calling code.

## Finding and opening a movie

The general file layer finds movies in either mounted MIX archives or the game directory. FFmpeg reads through an adapter over that layer, so a loose file and a member of either a cached or uncached archive use the same path. An archive member is not extracted to a temporary file.

A full-screen movie is shown only while all of these hold:

- the file exists;
- the session is a campaign game;
- FFmpeg finds a supported video stream and opens its decoder;
- the frame is not both narrower than 320 and shorter than 200.

Radar movies have no minimum-size check. Startup and menu movies pass the session check because the session has its campaign value while the menus are open. A missing, malformed, or unsupported movie is skipped; decoder errors are written to the debug log.

## Presentation

Full-screen frames are converted to BGRA8888 and submitted directly to the video backend, bypassing the game's RGB565 surfaces. Movies in the radar pane are converted to RGB565 to match its surface.

A full-screen movie normally keeps its decoded size. A caller may allow [`StretchMovies`](/keys/stretchmovies/) to fit it to the display without changing its aspect ratio. Any movie larger than the display is reduced to fit regardless of the setting. `TS_TITLE.VQA` and `FS_TITLE.VQA` do not grow when they already fit.

Escape stops a full-screen movie. The player then removes the BGRA override and returns presentation to the RGB565 game surface.

## Audio and timing

Audio is converted to interleaved signed 16-bit PCM and streamed through a dedicated DirectSound buffer at [`SoundVolume`](/keys/soundvolume/). Its playback position supplies the movie clock once samples begin playing. Video frames wait until their presentation timestamp; a frame is dropped when the next frame is already due, preventing accumulated video delay. A monotonic clock covers silent movies, an uninitialized audio device, and the interval before audio starts.

Playback ends after both the video and audio streams finish, so a shorter stream does not truncate the longer one. Full-screen playback holds the main game loop; [Play Movie](/scripting/actions/10/) covers the effect on music streaming.

## Pause and cleanup

Pausing a movie also pauses its audio and clock. Full-screen playback pauses when the game loses focus. A radar movie retains its last presented frame while gameplay is paused and resumes from the same position.

Ending a scenario or leaving radar movie mode releases queued movie and audio resources. In-game movies queued while another is playing are presented in order before the radar returns to its previous mode.

## Limits

The player selects one video stream and, when the audio device is initialized, one audio stream. A resolution change within a video stream stops that movie. Subtitles and other stream types are ignored.
