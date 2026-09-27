---
key: VeteranArmor
summary: Damage taken by an object holding the STRONGER ability is divided by this value plus one.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: "1"
---

Raising the value reduces the damage the object takes: the default halves it, and `0` leaves it unchanged. Only an object whose rank grants the `STRONGER` ability through [`VeteranAbilities`](/keys/veteranabilities/) or [`EliteAbilities`](/keys/eliteabilities/) is affected.

The reduction applies after the house's armor multiplier and any armor crate bonus, and before the warhead's [`Verses`](/keys/verses/) and distance falloff. At this stage a hit is never reduced below one point, but the warhead can still lower it afterward.

Forced damage and healing skip the reduction.
