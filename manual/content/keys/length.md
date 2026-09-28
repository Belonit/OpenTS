---
key: Length
summary: The playing time the sound options screen shows for a music track whose file does not state its own length.
see_also: [Name, Normal]
when_omitted:
  kind: value
  value: "0"
---

The sound options track list shows each track's length beside its [`Name`](/keys/name/#scope-themes), in minutes and seconds. The game reads that length from the track's file: from the header of an `.AUD`, `.WAV` or `.FLAC` file, and from the file itself for `.MP3` and `.OGG`. It uses `Length=` only for a file that does not state its length, or when the file was not found. That display is the only use the game makes of the value. Playback is not timed from it, so a length that disagrees with the audio file shows the wrong time and does not cut the track short or extend it.

The value is in minutes and may be fractional. The game converts it to seconds and drops any fraction of a second.

```ini title="theme.ini"
[VALVES1B]
Name=Valves
Length=3.27
```

If the length came from this key, the track would be listed as `3:16`, not `3:27`, because `.27` is a fraction of a minute. To show a length of *m*:*ss*, write *m* plus *ss*/60 and round the fraction up: `3.2667` shows `3:16`, while `3.2666` shows `3:15`.
