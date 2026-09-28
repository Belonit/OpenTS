---
key: Normal
summary: Offers the music track to the playlist the game picks from automatically.
see_also: [Repeat, Scenario, Side]
when_omitted:
  kind: value
  value: "yes"
---

```ini title="theme.ini"
[INTRO]
Name=Intro
Length=3.27
Normal=no
Repeat=yes
```

`Normal=no` keeps the track off the automatic playlist, so the game does not pick it when the current track ends. The track is also missing from the sound options track list, and the [next track](/commands/nexttheme/) and [previous track](/commands/prevtheme/) commands skip it.

The playlist never picks a track with `Normal=no`. When no track is allowed, the playlist plays nothing.

The setting does not stop other ways of starting the track. A scenario's [`Theme=`](/keys/theme/), the [Play music theme](/mapping/actions/taction-play-music/) trigger action and the [Play music](/mapping/missions/tmission-play-music/) team mission all play it. So do the main menu, map selection, the score screen and ion storms, which request their tracks by ID. The main menu can request `INTRO`, so the example track plays there, and [`Repeat=yes`](/keys/repeat/) keeps it looping.

[`Scenario=`](/keys/scenario/#scope-themes) and [`Side=`](/keys/side/#scope-themes) can also keep a track with `Normal=yes` off the playlist. [Choosing the next track](/systems/music/#choosing-the-next-track) lists every condition a track must meet.
