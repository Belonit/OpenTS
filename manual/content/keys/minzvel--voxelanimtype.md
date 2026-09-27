---
key: MinZVel
scope: voxelanimtype
label: Voxel debris launch speed
see_also: ["MaxZVel", "MaxXYVel", "IsMeteor"]
when_omitted:
  kind: value
  value: "3.5"
---

The speed is in leptons per frame (256 leptons to a cell, 15 frames to the second). Ordinary debris is thrown upward at this speed plus a random whole number of leptons per frame, up to [`MaxZVel`](/keys/maxzvel/). This is therefore the slowest launch the type produces. When `MaxZVel` equals this setting or is less than one lepton per frame above it, every piece launches at exactly this speed.

Keep `MaxZVel` at or above this setting. A maximum just below it crashes the game, as [`MaxZVel`](/keys/maxzvel/) describes.

A type whose section reads as below throws its debris upward at 3, 4, 5, 6, 7 or 8 leptons per frame.

```ini title="rules.ini"
[MYDEBRIS]     ; a VoxelAnimType, declared under [VoxelAnims]
MinZVel=3
MaxZVel=8
```

A meteor uses this setting as its vertical speed exactly, with no random addition and no reference to the maximum. The sign then decides the direction of approach, as [`IsMeteor`](/keys/ismeteor/#scope-voxelanimtype) describes.
