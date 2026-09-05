---
key: SoundVolume
summary: The volume of sound effects, as a fraction from 0 to 1.
see_also: [VoiceVolume, ScoreVolume]
when_omitted:
  kind: value
  value: ".7"
---

The fraction scales every sound effect on its way to the mixer, on top of the sound's own volume rating and whatever volume the caller asked for; a sound effect is not started at all while the fraction is zero or below. The same fraction sets the volume a full screen movie's audio track is played at, and the volume of the menu, briefing and score screen sounds.

The read holds the fraction to `1` at the top but not at the bottom, so a negative figure is stored as written. Nothing else clamps it, and the sounds it gates are simply never heard.

The sound options dialog offers the fraction as a ten-step slider, and leaving the options screen behind it writes the setting back to `sun.ini`.
