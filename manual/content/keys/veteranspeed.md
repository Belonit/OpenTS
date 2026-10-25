---
key: VeteranSpeed
summary: Movement speed of an object holding the faster ability is multiplied by one more than this value.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: "1"
---

Raising the value speeds the object up: the default doubles its movement speed, and `0` leaves it unchanged. Only an object whose rank grants the `FASTER` ability through [`VeteranAbilities`](/keys/veteranabilities/) or [`EliteAbilities`](/keys/eliteabilities/) is affected.

It reaches objects whose [`Locomotor`](/keys/locomotor/) is Drive, Hover, Walk, Mech, Tunnel or Fly: infantry, vehicles and aircraft. Every other locomotor, including Jumpjet and Levitate, sets its pace without reading the multiplier, so jumpjets and levitating objects gain nothing. A building has no speed to raise.

The multiplier applies after the house's ground-speed or air-speed multiplier, whichever the object's locomotor uses, and after any speed crate bonus.
