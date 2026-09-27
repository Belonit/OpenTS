---
key: VeteranROF
summary: Reload delay of an object holding the rate of fire ability is divided by this value plus one.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: "1"
---

Raising the value shortens the wait between shots: the default halves the reload delay, and `0` leaves it unchanged. Only an object whose rank grants the `ROF` ability through [`VeteranAbilities`](/keys/veteranabilities/) or [`EliteAbilities`](/keys/eliteabilities/) is affected.

The reduction applies after the house's rate-of-fire multiplier, and only to the delay that follows the last shot of a [`Burst`](/keys/burst/). The ability never shortens these delays:

- the gaps between the shots inside a burst;
- the delay of an [`IsSonic=yes`](/keys/issonic/) weapon;
- the delay of a [`UseSparkParticles=yes`](/keys/usesparkparticles/), [`UseFireParticles=yes`](/keys/usefireparticles/) or [`IsRailgun=yes`](/keys/israilgun/) weapon while its particle system is attached to the object;
- the delay of a building holding more than one round of [`Ammo`](/keys/ammo/).
