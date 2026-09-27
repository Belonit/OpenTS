---
key: IdleActionFrequency
summary: Base interval, in minutes, between one infantryman's idle actions.
see_also: [VoiceComment, Sequence, Fraidycat]
when_omitted:
  kind: value
  value: ".083"
---

```ini title="rules.ini"
[AudioVisual]
IdleActionFrequency=.15 ; the stock value, a wait of 4.5 to 18 seconds
```

After each idle action, an infantryman waits a random time between half this value and twice it before the next one. The value is in minutes. At 15 frames a second, the default `.083` gives a wait of between about two and a half and ten seconds. The setting applies to all infantry; lowering it makes every infantryman idle more often.

The wait is a minimum. When it has passed, the infantryman idles at the next check of its guard, hunt or area guard mission, and only if all of these hold:

- it is standing in its guard or ready stance;
- it is not moving, firing or prone;
- it has no target nearby.

Each idle action is one of eleven equally likely outcomes. The animations are the `Idle1` and `Idle2` entries of the infantry type's [`Sequence`](/keys/sequence/).

| Outcomes | Action |
| --- | --- |
| 3 | Plays the `Idle1` animation. |
| 3 | Plays the `Idle2` animation and turns to a random facing. |
| 4 | Turns to a random facing. |
| 1 | Does nothing. |

On an `Idle2` outcome, an infantryman the player owns and has not selected has a one-in-three chance to play the first sound in its [`VoiceComment`](/keys/voicecomment/) list.

A computer-owned [`Fraidycat=yes`](/keys/fraidycat/) infantryman also scatters. It scatters in place of the idle action while it is frightened, and on one of the four turning outcomes otherwise.

Vehicles, aircraft and structures have no idle actions.
