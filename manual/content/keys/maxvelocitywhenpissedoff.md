---
key: MaxVelocityWhenPissedOff
summary: The speed at which a levitating unit closing on a target gives up coasting and brakes.
see_also: ["MaxVelocityWhenFollowing", "MaxVelocityWhenHappy", "IntentionalDeacceleration", "ProximityDistance"]
when_omitted:
  kind: value
  value: "6.5"
---

A levitating unit with a target coasts after each thrust until its speed falls *below* this figure, then brakes. It also brakes if the target comes within [`ProximityDistance`](/keys/proximitydistance/). Braking runs at [`IntentionalDeacceleration`](/keys/intentionaldeacceleration/) until the unit stops, and the unit then steers at the target again.

The figure applies whenever the unit has a target, even when it also has a destination. The target must be an infantry, vehicle, aircraft or structure on the map; a unit ordered to fire at the ground counts as having no target. A unit with only a destination uses [`MaxVelocityWhenFollowing`](/keys/maxvelocitywhenfollowing/) instead.

Like `MaxVelocityWhenFollowing`, the figure sets how long a coast lasts, not how fast the unit may go. A higher figure ends each coast sooner, so with this key above `MaxVelocityWhenFollowing`, as it is by default, a unit closing on a target coasts less between thrusts than one heading for a destination. `MaxVelocityWhenFollowing` explains why raising the figure too far makes the unit slower on average.

:::caution[Keep MaxVelocityWhenPissedOff above 0]
At `0` or below, a coasting unit never slows below the figure, so it never brakes on speed. [`Drag`](/keys/drag/) brings it to a halt, and it stays there, because a stopped unit thrusts again only after braking. It moves again only when its target comes within `ProximityDistance` or it loses the target.
:::

[`Drag`](/keys/drag/) explains which objects use `[LEVITATION]` and why a file's `[LEVITATION]` section is read only when the file also has a `[General]` section.
