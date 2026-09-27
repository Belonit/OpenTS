---
key: MinAngularVelocity
summary: The bottom of the range a voxel animation's tumbling rate is drawn from, in degrees per frame.
see_also: ["MaxAngularVelocity", "Duration"]
when_omitted:
  kind: value
  value: "-1"
---

The setting is in degrees per frame, and the engine works with it in radians. Each piece draws one tumbling rate when it is created and keeps it for its whole life.

In practice the rate is usually this minimum. The random part of the pick adds whole radians, about 57 degrees each. It adds something only when [`MaxAngularVelocity`](/keys/maxangularvelocity/) is at least about 57 degrees above this setting, or at least about 172 degrees below it.

Writing exactly `0` changes nothing. The minimum keeps the value the previous read of the section left, or 0 if no earlier file declared the section.

:::danger[Write MaxAngularVelocity whenever you write this key]
When a section leaves out [`MaxAngularVelocity`](/keys/maxangularvelocity/), its maximum is minus one degree per frame, not the built-in ten. A minimum above minus one degree and below about 113.6 degrees then makes the random pick divide by zero, and the game crashes as soon as a piece of the type is created. Meteors are affected too.

To avoid it, write `MaxAngularVelocity` at or above this setting, or keep this setting at minus one degree or lower.
:::
