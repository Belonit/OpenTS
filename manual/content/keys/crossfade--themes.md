---
key: CrossFade
scope: themes
label: Music crossfade time
see_also: [FadeOut]
when_omitted:
  kind: value
  value: "0"
  note: No crossfade, so a queued track waits until the current one has faded out.
---

`CrossFade=` in THEME.INI's `[General]` section sets, in seconds, how long a queued music track overlaps the track it replaces. The queued track starts at once and rises from silence to its own [`Volume=`](/keys/volume/#scope-themes) over that time, while the current track fades out over the same time.

```ini title="theme01.ini"
[General]
CrossFade=4
```

Tracks are queued by the [Play music theme](/mapping/actions/taction-play-music/) trigger action, the [Play music](/mapping/missions/tmission-play-music/) team mission, and the move from a scenario's [`Theme=`](/keys/theme/) track to the playlist when a mission begins. A track that ends by itself, or one started at once, such as the main menu track, does not crossfade. An ion storm's track crossfades over this time with the track it pauses, both when the storm breaks and when it ends. Stopping the music uses [`FadeOut=`](/keys/fadeout/).

When another track is queued during a crossfade, the track that was already fading out is cut within a tenth of a second, so no more than two tracks are heard at once. A value of zero or below turns the crossfade off, and one above 60 counts as 60.
