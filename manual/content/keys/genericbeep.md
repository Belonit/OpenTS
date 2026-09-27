---
key: GenericBeep
summary: Sound confirming a new level on a volume slider.
see_also: [GenericClick, SpeakDelay]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
GenericBeep=BEEP1 ; a sound ID registered in SOUND.INI
```

The sound options dialog plays this sound each time one of its three volume sliders changes level, so the new level can be heard. Each slider has its own condition:

- **Music volume.** The sound plays, scaled by the new music volume, only while no music track is playing.
- **Sound effects volume.** The sound plays at every change of level.
- **Speech volume.** Outside a game, the sound plays, scaled by the new speech volume. During a game, moving the slider speaks a random GDI or Nod taunt instead, and only when no other speech is playing.
