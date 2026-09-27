---
key: AccelerationDuration
summary: How many frames a levitating unit's thrust keeps pushing.
see_also: ["Acceleration", "InitialBoost", "Drag", "AccelerationProbability"]
when_omitted:
  kind: value
  value: "20"
---

A thrust adds [`Acceleration`](/keys/acceleration/#scope-levitation-controls) to the unit's speed on each of this many frames, and then the unit coasts. At `20`, a thrust lasts a little over a second. A larger figure makes each thrust last longer, and while `Acceleration` exceeds [`Drag`](/keys/drag/) it also raises the speed the thrust reaches; the `Acceleration` page gives that speed.

Only two things end a thrust early. If the unit's target or destination comes within [`ProximityDistance`](/keys/proximitydistance/), the unit brakes. If a move is blocked, the unit drifts back to the center of its cell. The speed figures such as [`MaxVelocityWhenFollowing`](/keys/maxvelocitywhenfollowing/) are not checked until the thrust has ended.

At `0`, a thrust adds no acceleration, so each thrust gives the unit only its [`InitialBoost`](/keys/initialboost/).

:::caution[Keep AccelerationDuration at 0 or above]
A negative figure starts thrusts that never end. The unit gets only its `InitialBoost`, coasts to a halt under [`Drag`](/keys/drag/), and stays there without thrusting again or reclaiming its cell. The stuck thrust ends only when the unit's target or destination comes within `ProximityDistance` or a move is blocked, and the next thrust strands the unit the same way.
:::

[`Drag`](/keys/drag/) explains which objects use `[LEVITATION]` and why a file's `[LEVITATION]` section is read only when the file also has a `[General]` section.
