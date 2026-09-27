---
key: SoundVolume
summary: The volume of sound effects, as a fraction from 0 to 1.
see_also: [VoiceVolume, ScoreVolume, SoundLatency]
when_omitted:
  kind: value
  value: ".7"
---

`SoundVolume` sets the level of every sound effect and of every movie's soundtrack, briefings included. Sound effects include unit responses and the sounds of the menus and the score screen. The fraction multiplies the final volume of every sound effect and movie soundtrack, including sounds already playing.

At `0` or below, sound effects and movie soundtracks are silent.

Values above `1` are read as `1`. A negative value is kept and saved back as written until the player presses OK in the sound options. OK stores the slider's position, which rounds the level to the nearest tenth and turns a negative value into `0`.

The sound options dialog offers the fraction as a ten-step slider. Moving the slider changes the level at once and plays a beep. The level is saved to `sun.ini` when the player leaves the options menu. During a game, the sound options return to the game controls dialog, and the level is saved when that dialog is accepted.
