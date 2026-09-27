---
key: Spawns
scope: voxelanimtype
label: Voxel meteor spawn type
see_also: ["SpawnCount", "IsMeteor", "IsTiberium"]
when_omitted:
  kind: value
  value: none
---

`Spawns` names the voxel animation type that a meteor breaks into when it strikes. [`SpawnCount`](/keys/spawncount/#scope-voxelanimtype) sets how many pieces appear.

Only an [`IsMeteor=yes`](/keys/ismeteor/#scope-voxelanimtype) type spawns pieces. A meteor that ends its flight over water spawns nothing unless it is at least 416 leptons above the ground there, the height of a bridge deck.

All the pieces appear in the same frame. Ordinary debris starts at the impact point, and a spawned meteor type flies in toward it. The pieces belong to no house, so a piece with [`IsTiberium=yes`](/keys/istiberium/#scope-voxelanimtype) is drawn in Tiberium colors. Debris thrown off a destroyed object takes its owner's house colors instead.

A name missing from `[VoxelAnims]` still creates a voxel animation type of that name. If that file or a later rules or map file declares a section with that name, the type reads it. Otherwise the type has no model and every setting at its built-in value, so its pieces are invisible.

:::caution[A meteor that spawns itself can multiply without limit]
If `Spawns` names the meteor's own type, or a chain of meteor types leads back to it, each impact launches new meteors toward the point where it struck. At a `SpawnCount` of `1` each impact produces one meteor on average. At `2` or more the number of meteors usually grows with every generation, and each impact on land can deform the terrain again, as [`CraterLevel`](/keys/craterlevel/) sets.
:::
