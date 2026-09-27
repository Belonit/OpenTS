---
key: VoxelBarrelOffsetToRotatePivotPoint
summary: Where a building's voxel barrel sits once it has turned to face its target.
see_also: ["BarrelAnimIsVoxel", "VoxelBarrelOffsetToBuildingPivotPoint", "VoxelBarrelOffsetToPitchPivotPoint", "VoxelBarrelOffsetToBarrelEnd", "PrimaryFireFLH"]
when_omitted:
  kind: value
  value: "0,0,0"
---

Three whole numbers, `X,Y,Z`, that move the barrel of a [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building away from the axis the gun turns about. At `0,0,0` the point the barrel tilts about sits on that axis.

The building places its barrel in five steps, in this order:

1. Move by [`VoxelBarrelOffsetToBuildingPivotPoint`](/keys/voxelbarreloffsettobuildingpivotpoint/).
2. Turn to the gun's current facing.
3. Move by `VoxelBarrelOffsetToRotatePivotPoint`.
4. Tilt to the barrel's current pitch.
5. Move by [`VoxelBarrelOffsetToPitchPivotPoint`](/keys/voxelbarreloffsettopitchpivotpoint/).

The barrel model is drawn at the point these steps reach, at the size [`VoxelBarrelScale`](/keys/voxelbarrelscale/) sets.

This offset comes after the turn and before the tilt, so it turns with the gun but stays put as the barrel rises. `X` runs forward along the gun's facing, `Y` to its left, and `Z` up. For an object without a voxel barrel, [`PrimaryFireFLH`](/keys/primaryfireflh/) is applied at this same step and in the same axes.

```ini title="rules.ini"
[MYARTILLERY] ; a BuildingType registered in [BuildingTypes]
BarrelAnimIsVoxel=yes
VoxelBarrelOffsetToBuildingPivotPoint=4,2,3
VoxelBarrelOffsetToRotatePivotPoint=2,0,0 ; two units forward of the mount
VoxelBarrelOffsetToPitchPivotPoint=15,0,-8
VoxelBarrelOffsetToBarrelEnd=350,75,0
```

The barrel model is drawn with the three pivot offsets in voxel model units, but shots start from a point that uses the same numbers as leptons, 256 to a cell. A pivot offset therefore moves the drawn barrel farther than it moves the shots. [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/) moves only the shots, so it is in leptons alone.

When the building's art entry sets [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/), shots start from that offset, and the barrel offsets do not move them. A building that also sets [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) draws its barrel without these offsets, as [`BarrelAnimIsVoxel`](/keys/barrelanimisvoxel/) explains.

A value that does not begin with three whole numbers separated by commas, such as `2,0` or `2.5,0,0`, is ignored. The building keeps the offset it had before that line was read. Text after the third number is dropped, so `2,0,0,5` reads as `2,0,0`.
