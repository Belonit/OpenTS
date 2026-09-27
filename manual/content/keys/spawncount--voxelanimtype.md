---
key: SpawnCount
scope: voxelanimtype
label: Voxel meteor spawn count
see_also: ["Spawns", "IsMeteor"]
when_omitted:
  kind: value
  value: "0"
---

A meteor's impact creates between 0 and twice `SpawnCount` pieces of the [`Spawns`](/keys/spawns/#scope-voxelanimtype) type, `SpawnCount` on average. The count is the sum of two random numbers, each from 0 to `SpawnCount`, so counts near `SpawnCount` are the most likely. A setting of 0 or less spawns nothing.

Only an [`IsMeteor=yes`](/keys/ismeteor/#scope-voxelanimtype) type spawns pieces, and not when it ends low over water. [`Spawns`](/keys/spawns/#scope-voxelanimtype) gives the conditions.
