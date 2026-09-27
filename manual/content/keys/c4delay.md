---
key: C4Delay
summary: The delay in minutes between arming a demolition charge and its detonation.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: ".03"
---

`C4Delay` sets how long a demolition charge counts down before it detonates. A game minute is 900 frames, so the engine default of `.03` is 27 frames, about 1.8 seconds at 15 frames a second.

The structure flashes as a designated target for half the countdown, so a longer delay also gives a longer warning.

```ini title="rules.ini"
[CombatDamage]
C4Delay=.1  ; 90 frames, a 6 second fuse at 15 frames a second
```

Nothing cancels or shortens the countdown once it is running. [Detonation](/systems/capture/#detonation) covers the damage that ends it.
