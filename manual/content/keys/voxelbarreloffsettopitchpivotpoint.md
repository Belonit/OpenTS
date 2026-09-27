---
key: VoxelBarrelOffsetToPitchPivotPoint
summary: Where a building's voxel barrel sits once it has elevated.
see_also: ["BarrelAnimIsVoxel", "VoxelBarrelOffsetToBuildingPivotPoint", "VoxelBarrelOffsetToRotatePivotPoint", "VoxelBarrelOffsetToBarrelEnd", "PBarrelLength"]
when_omitted:
  kind: value
  value: "0,0,0"
---

Three whole numbers, `X,Y,Z`, that place the barrel model of a [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building relative to the point it tilts about. That point stays still while the rest of the barrel rises and falls. At `0,0,0` the barrel tilts about the model's origin.

The building places its barrel in five steps, in this order:

1. Move by [`VoxelBarrelOffsetToBuildingPivotPoint`](/keys/voxelbarreloffsettobuildingpivotpoint/).
2. Turn to the gun's current facing.
3. Move by [`VoxelBarrelOffsetToRotatePivotPoint`](/keys/voxelbarreloffsettorotatepivotpoint/).
4. Tilt to the barrel's current pitch.
5. Move by `VoxelBarrelOffsetToPitchPivotPoint`.

The barrel model is drawn at the point these steps reach, at the size [`VoxelBarrelScale`](/keys/voxelbarrelscale/) sets.

This offset comes after the tilt, so it rises and falls with the barrel. `X` runs out along the tilted barrel, `Y` to its left, and `Z` at right angles to both. For an object without a voxel barrel, [`PBarrelLength`](/keys/pbarrellength/) is applied at this same step, but only along `X`.

```ini title="rules.ini"
[MYARTILLERY] ; a BuildingType registered in [BuildingTypes]
BarrelAnimIsVoxel=yes
VoxelBarrelOffsetToBuildingPivotPoint=4,2,3
VoxelBarrelOffsetToRotatePivotPoint=2,0,0
VoxelBarrelOffsetToPitchPivotPoint=15,0,-8 ; forward along the barrel and slightly below it
VoxelBarrelOffsetToBarrelEnd=350,75,0
```

The barrel model is drawn with the three pivot offsets in voxel model units, but shots start from a point that uses the same numbers as leptons, 256 to a cell. A pivot offset therefore moves the drawn barrel farther than it moves the shots. [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/) moves only the shots, so it is in leptons alone.

When the building's art entry sets [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/), shots start from that offset, and the barrel offsets do not move them. A building that also sets [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) draws its barrel without these offsets, as [`BarrelAnimIsVoxel`](/keys/barrelanimisvoxel/) explains.

A value that does not begin with three whole numbers separated by commas, such as `15,0` or `15.5,0,-8`, is ignored. The building keeps the offset it had before that line was read. Text after the third number is dropped, so `15,0,-8,2` reads as `15,0,-8`.
