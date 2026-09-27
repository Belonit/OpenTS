---
key: MaxDebris
summary: The number of pieces of wreckage a destroyed object may throw.
see_also: [DebrisTypes, DebrisMaximums, MetallicDebris, ExplosiveVoxelDebris]
when_omitted:
  kind: value
  value: "0"
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
MaxDebris=6
DebrisTypes=MYSCRAP,MYTIRE ; VoxelAnimTypes registered in [VoxelAnims]
DebrisMaximums=4,2
```

At `0`, a destroyed object throws no wreckage, whatever its debris lists say. Above `0`, the value caps the total number of pieces. Which pieces are thrown depends on whether the type sets [`DebrisTypes`](/keys/debristypes/):

- **With `DebrisTypes`**, the entries are taken in order. Each throws a random number of pieces, from zero up to its matching [`DebrisMaximums`](/keys/debrismaximums/) figure, until `MaxDebris` pieces have been thrown. Give every entry a figure of `0` or more, or the game can crash when the object is destroyed. Any budget left after the last entry goes unused. The pieces start at the object's center and belong to the object's owner.
- **Without `DebrisTypes`**, a random number of pieces from zero up to `MaxDebris` is thrown, each a [`MetallicDebris`](/keys/metallicdebris/) animation picked at random, 20 leptons above the object's center.

In the example, `MYSCRAP` throws zero to four pieces and `MYTIRE` zero to two. Their maximums add up to six, so the budget never cuts a draw short.

Wreckage is thrown after the death voice and before any [`Explodes=yes`](/keys/explodes/#scope-aircrafttype) blast. An object that has fallen from a height, for example off a bridge, and dies over water within 10 leptons of the ground throws no wreckage and does not explode.
