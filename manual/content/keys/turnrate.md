---
key: TurnRate
summary: How fast a jumpjet unit swings around to a new heading.
see_also: [Speed, Acceleration, ROT]
when_omitted:
  kind: value
  value: "3"
---

`TurnRate` is how far a jumpjet turns each game frame, in 256ths of a full rotation. It uses the same scale as an object's [`ROT`](/keys/rot/#scope-aircrafttype). A turn takes its arc divided by this rate, rounded down to whole frames. No single turn is wider than a half circle, so a full about-face takes `128 ÷ TurnRate` frames: 42 frames at the default `3`, a little under three seconds.

```ini title="rules.ini"
[JumpjetControls]
TurnRate=4
```

A jumpjet takes the rate when it is created and keeps it for the rest of the game.

A jumpjet does not wait for a turn to finish before it moves. Once it has climbed past a quarter of its flight level, it accelerates along whatever heading it currently faces, and that heading keeps swinging toward the destination as it flies. A low rate therefore sends it off in a wide curve.

A value above `127` is treated as `127`, half a rotation per frame. At `0`, or at any value down to `-128`, the jumpjet snaps to each new heading without turning. Lower values wrap around as they do for `ROT`, and some of them give an ordinary turning rate.
