---
key: ExplosiveVoxelDebris
summary: Parsed VoxelAnimType list that the engine never uses.
no_effect: true
see_also: [ScrapVoxelDebris, TireVoxelDebris, DebrisTypes]
when_omitted:
  kind: value
  value: ""
---

The single-type settings [`ScrapVoxelDebris`](/keys/scrapvoxeldebris/) and [`TireVoxelDebris`](/keys/tirevoxeldebris/) beside this list have no effect either.

Each type chooses its own destruction debris. A type with [`MaxDebris`](/keys/maxdebris/) above zero throws pieces from its [`DebrisTypes`](/keys/debristypes/) list, capped per entry by [`DebrisMaximums`](/keys/debrismaximums/). A type with `MaxDebris` above zero and no `DebrisTypes` throws [`MetallicDebris`](/keys/metallicdebris/) animations instead.
