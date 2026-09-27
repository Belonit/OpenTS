---
key: WindEffect
summary: How strongly the prevailing wind carries a particle sideways.
see_also: ["BehavesLike", "Velocity", "WindDirection"]
when_omitted:
  kind: value
  value: "0"
---

The wind moves a particle by a step of up to two leptons on each axis, in the direction [`WindDirection`](/keys/winddirection/) names. For `Gas` and `WeakGas` particles, this value sets how often the step is taken. For `Smoke` particles, it sets how large the step is. `Fire`, `Spark`, `Railgun` and `Web` particles ignore it. The behavior is set by [`BehavesLike`](/keys/behaveslike/#scope-particletype).

`Gas` and `WeakGas` particles take the step once every N frames, where N is 10 divided by this value and rounded down. The scale is coarse and reaches every frame quickly:

| Value | Step taken |
| --- | --- |
| `0` or less | never |
| `1` | one frame in ten |
| `2` | one frame in five |
| `3` | one frame in three |
| `4` or `5` | every other frame |
| `6` through `10` | every frame |

`Smoke` particles take the step every frame, multiplied by this value. The drift has no upper limit, and a negative value carries the puff upwind.

:::danger[Keep gas values at 10 or below]
For `Gas` and `WeakGas` particles, a value of `11` or more rounds the interval down to zero. The game divides by zero and crashes as soon as a particle of the type moves. `Smoke` particles accept any value.
:::
