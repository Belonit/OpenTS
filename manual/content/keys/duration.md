---
key: Duration
summary: How many frames a voxel animation lives before it performs its impact and is removed.
see_also: ["IsMeteor", "Elasticity", "ExpireAnim"]
when_omitted:
  kind: value
  value: "30"
---

The piece's lifetime in game frames, 15 to the second. When the lifetime runs out, the piece performs its impact and is removed. What the impact does depends on where the piece is:

- Anywhere except low over water, the impact plays [`ExpireAnim`](/keys/expireanim/#scope-voxelanimtype) with its blast and plays [`ExpireSound`](/keys/expiresound/#scope-voxelanimtype). A meteor also releases its [`Spawns`](/keys/spawns/#scope-voxelanimtype) and can crater the ground, and [`IsTiberium`](/keys/istiberium/#scope-voxelanimtype) debris can seed Tiberium.
- Low over water, the piece plays a splash instead, as `ExpireAnim` describes.

A piece can end sooner. One that comes to rest, or strikes something in a water cell, has its lifetime ended at once and performs the impact on the next frame. A value of `0` or below performs the impact on the piece's first frame, before it has moved.

A meteor's lifetime is shortened by a random 0 to 19 frames when it is created. The meteor starts as far back from its target as its velocity covers in that shortened lifetime. For a meteor, this setting therefore sets how far away it appears as well as how long it lives. [`IsMeteor`](/keys/ismeteor/#scope-voxelanimtype) describes the flight.
