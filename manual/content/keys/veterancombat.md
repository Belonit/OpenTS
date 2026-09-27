---
key: VeteranCombat
summary: Weapon damage from an object holding the firepower ability is multiplied by this value plus one.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: "1"
---

Raising the value increases the damage the object's weapons deal: the default doubles it, and `0` leaves it unchanged. Only an object whose rank grants the `FIREPOWER` ability through [`VeteranAbilities`](/keys/veteranabilities/) or [`EliteAbilities`](/keys/eliteabilities/) is affected.

The multiplier applies last, after the house's firepower multiplier and any firepower crate bonus. It never raises these weapons:

- a sonic weapon or a weapon that fires through the fire particle system, because their damage does not come from the projectile this multiplier scales;
- a weapon with negative damage, such as a healing weapon.
