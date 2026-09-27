---
key: AccelerationProbability
summary: The per-frame chance that a levitating unit with nothing to head for thrusts off in a random direction.
see_also: ["MaxVelocityWhenHappy", "AccelerationDuration", "PropulsionSoundEffect"]
when_omitted:
  kind: value
  value: "0.01"
---

A levitating unit with neither a target nor a destination wanders by thrusting in random directions. On each frame it may thrust, it rolls a fraction from `0` to `1` and starts a thrust when the roll is below this figure. The direction is random over the whole circle, so the wandering has no bias.

The unit rolls in two situations:

- It is at rest, and its mission is neither sticky nor sleep.
- It is coasting after an earlier thrust, at a speed below [`MaxVelocityWhenHappy`](/keys/maxvelocitywhenhappy/). The mission is not checked here.

At `0.01`, a unit at rest starts a thrust about once every 100 frames, roughly every seven seconds. At `0`, a levitating unit with nothing to head for never starts a thrust, so once at rest it stays put. At `1` or more, it thrusts on every frame it is allowed to.

[`Drag`](/keys/drag/) explains which objects use `[LEVITATION]` and why a file's `[LEVITATION]` section is read only when the file also has a `[General]` section.
