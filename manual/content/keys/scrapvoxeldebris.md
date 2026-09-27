---
key: ScrapVoxelDebris
summary: Parsed VoxelAnimType that the engine never uses.
no_effect: true
see_also: [ExplosiveVoxelDebris, TireVoxelDebris, DebrisTypes]
when_omitted:
  kind: value
  value: none
---

The name suggests the scrap a destroyed vehicle throws, but nothing in the game uses this setting. A destroyed object's debris is set by its type through [`DebrisTypes`](/keys/debristypes/) and related keys, as [`ExplosiveVoxelDebris`](/keys/explosivevoxeldebris/) describes.

Naming a voxel animation the game does not know yet still registers a voxel animation type of that name.
