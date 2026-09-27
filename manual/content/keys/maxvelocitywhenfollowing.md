---
key: MaxVelocityWhenFollowing
summary: The speed at which a levitating unit heading for a destination gives up coasting and brakes.
see_also: ["MaxVelocityWhenPissedOff", "MaxVelocityWhenHappy", "IntentionalDeacceleration", "ProximityDistance"]
when_omitted:
  kind: value
  value: "5"
---

A levitating unit with a destination and no target coasts after each thrust until its speed falls *below* this figure, then brakes. It also brakes if the destination comes within [`ProximityDistance`](/keys/proximitydistance/). Braking runs at [`IntentionalDeacceleration`](/keys/intentionaldeacceleration/) until the unit stops, and the unit then steers at the destination again. A unit with a target uses [`MaxVelocityWhenPissedOff`](/keys/maxvelocitywhenpissedoff/) instead, even when it also has a destination.

Despite the name, the figure is not a speed limit, and nothing caps a levitating unit's speed. The figure sets how long the unit coasts, and the unit thrusts again only after it has braked. A higher figure shortens the coast and brings the next thrust sooner.

Raising the figure helps only up to a point when `IntentionalDeacceleration` is larger than `Drag`, as it is by default, because braking then sheds speed faster than coasting. Once the figure reaches the speed a thrust ends at, which the [`Acceleration`](/keys/acceleration/#scope-levitation-controls) page shows how to work out, the unit brakes straight out of every thrust and never coasts. With every other `[LEVITATION]` key at its default, the unit then averages a lower speed than it does with this key omitted.

:::caution[Keep MaxVelocityWhenFollowing above 0]
At `0` or below, a coasting unit never slows below the figure, so it never brakes on speed. [`Drag`](/keys/drag/) brings it to a halt, and it stays there, because a stopped unit thrusts again only after braking. It moves again only when its destination comes within `ProximityDistance`, when it is given a target, or when it loses its destination. A new move order to a point farther away leaves it stuck.
:::

[`Drag`](/keys/drag/) explains which objects use `[LEVITATION]` and why a file's `[LEVITATION]` section is read only when the file also has a `[General]` section.
