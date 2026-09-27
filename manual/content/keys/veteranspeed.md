---
key: VeteranSpeed
summary: Movement speed of an object holding the faster ability is multiplied by one more than this value.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: "1"
---

Raising the value speeds the object up: the default doubles its movement speed, and `0` leaves it unchanged. Only an object whose rank grants the `FASTER` ability through [`VeteranAbilities`](/keys/veteranabilities/) or [`EliteAbilities`](/keys/eliteabilities/) is affected.

The multiplier applies after the house's ground-speed multiplier and any speed crate bonus.

It reaches infantry and vehicles whose [`Locomotor`](/keys/locomotor/) is Drive, Hover, Walk, Mech or Tunnel. Every other locomotor, including Flyer, Jumpjet and Levitate, sets its pace without reading the multiplier, so aircraft, jumpjets and levitating objects gain nothing. A building has no speed to raise.
