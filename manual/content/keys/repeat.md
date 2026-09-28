---
key: Repeat
summary: Makes the music track start again when it ends instead of handing over to the next one.
see_also: [Normal, Scenario]
when_omitted:
  kind: value
  value: "no"
---

```ini title="theme.ini"
[INTRO]
Name=Intro
Repeat=yes
```

`Repeat=yes` plays the track again from its beginning each time it reaches its end, with no gap, whether shuffle is on or off. The game does not move on to another track by itself. The track keeps playing until something else changes the music, such as a new scenario. [Choosing the next track](/systems/music/#choosing-the-next-track) lists what can interrupt a repeating track.

The setting matters most for a track that is [started immediately](/systems/music/#choosing-the-next-track), such as the map selection, score screen or ion storm track, or the main menu track when the menu first opens. When such a track ends outside a game, the music stops unless it repeats or another track has been queued; during a game, the next allowed track follows.

The repeat option on the sound options screen, stored as [`IsScoreRepeat`](/keys/isscorerepeat/), repeats every track. A track with `Repeat=yes` repeats whether that option is on or off.
