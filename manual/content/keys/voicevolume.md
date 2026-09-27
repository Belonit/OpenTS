---
key: VoiceVolume
summary: The volume of EVA and taunt speech, as a fraction from 0 to 1.
see_also: [SoundVolume, ScoreVolume]
when_omitted:
  kind: value
  value: "1"
---

`VoiceVolume` sets the level of EVA announcements, multiplayer taunts and the voice on the campaign map selection screen. A change also applies to the line already speaking. Unit responses are sound effects and follow [`SoundVolume`](/keys/soundvolume/) instead.

Below 1/255, which includes `0` and every negative value, speech is refused: nothing is queued and nothing is spoken.

Values above `1` are read as `1`. A negative value is kept and saved back as written until the player presses OK in the sound options. OK stores the slider's position, which rounds the level to the nearest tenth and turns a negative value into `0`.

The sound options dialog offers the fraction as a ten-step slider, and moving the slider changes the level at once. During a game it plays a random taunt as a sample, unless a line is already playing; outside a game it plays a beep. The level is saved to `sun.ini` when the player leaves the options menu. During a game, the sound options return to the game controls dialog, and the level is saved when that dialog is accepted.
