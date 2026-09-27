---
key: Length
summary: The playing time of the music track, in minutes, shown beside its name on the sound options screen.
see_also: [Name, Normal]
when_omitted:
  kind: value
  value: "0"
---

The sound options track list shows this length beside the track's [`Name`](/keys/name/#scope-themes), in minutes and seconds. That display is the only use the game makes of the value. Playback is not timed from it, so a length that disagrees with the audio file shows the wrong time and does not cut the track short or extend it.

The value is in minutes and may be fractional. The game converts it to seconds and drops any fraction of a second.

```ini title="theme.ini"
[VALVES1B]
Name=Valves
Length=3.27
```

This track is listed as `3:16`, not `3:27`, because `.27` is a fraction of a minute. To show a length of *m*:*ss*, write *m* plus *ss*/60 and round the fraction up: `3.2667` shows `3:16`, while `3.2666` shows `3:15`.
