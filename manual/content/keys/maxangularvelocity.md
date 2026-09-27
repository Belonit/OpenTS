---
key: MaxAngularVelocity
summary: The top of the range a voxel animation's tumbling rate is drawn from, in degrees per frame.
see_also: ["MinAngularVelocity", "Duration"]
when_omitted:
  kind: value
  value: "-1"
---

Each piece tumbles at one rate for its whole life, drawn when it is created from the range between [`MinAngularVelocity`](/keys/minangularvelocity/) and this setting.

A value of exactly `0` is ignored, and the type keeps the maximum it already held. On the type's first read, that is ten degrees per frame. Every other value, negative ones included, is used as written.

:::caution[The pick moves in steps of about 57 degrees]
The rate is picked in steps of one radian, about 57 degrees per frame, counted up from the minimum. If this setting is less than about 57 degrees above the minimum, every piece tumbles at exactly the minimum rate and this setting has no effect. A wider range adds only whole steps: the minimum plus 57, plus 114, and so on.
:::

:::danger[A maximum just below the minimum crashes the game]
If this setting is below `MinAngularVelocity` by less than about 114.6 degrees, the game crashes when a piece of the type is created. Leaving this setting out while writing a minimum above -1 and below about 113.6 degrees has the same result, because an omitted maximum is -1 degree per frame.
:::
