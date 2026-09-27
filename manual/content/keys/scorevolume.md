---
key: ScoreVolume
summary: The volume of the music, as a fraction from 0 to 1.
see_also: [SoundVolume, VoiceVolume, IsScoreRepeat, IsScoreShuffle]
when_omitted:
  kind: value
  value: ".5"
---

`0` silences the music and `1` plays it at full volume. A change applies at once to the track already playing, without restarting it. At zero, no new track starts; [Focus and volume](/systems/music/#focus-and-volume) describes what happens to queued and playing tracks until the volume is raised.

A value above `1` is read as `1`. A negative value is kept as written, and no track starts until the slider in the sound options dialog is moved above zero.

The sound options dialog sets the volume with a ten-step slider. The change is written to `sun.ini` when the player leaves the options menu or, during a game, closes the game controls dialog with OK. While the volume is zero, the credits screen plays its track at `.4` and restores the stored volume when it closes.
