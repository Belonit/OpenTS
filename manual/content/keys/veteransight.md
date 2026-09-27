---
key: VeteranSight
summary: Sight range of an object holding the sight ability is multiplied by one more than this value.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: "1"
---

Raising the value widens the area the object reveals: the default doubles its sight range, and `0` leaves it unchanged. Only an object whose rank grants the `SIGHT` ability through [`VeteranAbilities`](/keys/veteranabilities/) or [`EliteAbilities`](/keys/eliteabilities/) is affected.

Fractional values work: `0.5` gives one and a half times the range. At `-1` the object reveals nothing. The result is rounded down to whole cells.

The multiplier applies after the height bonus that [`LeptonsPerSightIncrease`](/keys/leptonspersightincrease/) sets. [Sight range](/systems/map-visibility/#sight-range) gives the full calculation.

Aircraft never gain from the ability, because their sight uses the type's range alone.

The wider range takes effect the next time the object reveals the terrain around it, not at the moment it is promoted.
