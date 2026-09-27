---
key: VoxelBarrelOffsetToBuildingPivotPoint
summary: Where a building's voxel barrel assembly is mounted on the structure.
see_also: ["BarrelAnimIsVoxel", "VoxelBarrelOffsetToRotatePivotPoint", "VoxelBarrelOffsetToPitchPivotPoint", "VoxelBarrelOffsetToBarrelEnd", "VoxelBarrelScale"]
when_omitted:
  kind: value
  value: "0,0,0"
---

Three whole numbers, `X,Y,Z`, that move the whole barrel assembly of a [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building away from its turret position. The turret position is the point the building is drawn at, moved by [`TurretAnimX`](/keys/turretanimx/) and [`TurretAnimY`](/keys/turretanimy/). At `0,0,0` the assembly sits on the turret position.

The building places its barrel in five steps, in this order:

1. Move by `VoxelBarrelOffsetToBuildingPivotPoint`.
2. Turn to the gun's current facing.
3. Move by [`VoxelBarrelOffsetToRotatePivotPoint`](/keys/voxelbarreloffsettorotatepivotpoint/).
4. Tilt to the barrel's current pitch.
5. Move by [`VoxelBarrelOffsetToPitchPivotPoint`](/keys/voxelbarreloffsettopitchpivotpoint/).

The barrel model is drawn at the point these steps reach, at the size [`VoxelBarrelScale`](/keys/voxelbarrelscale/) sets.

This offset comes before the turn, so it stays put while the gun turns, and its axes are the map's. `X` runs toward the lower right of the screen, `Y` toward the upper right, and `Z` up.

```ini title="rules.ini"
[MYARTILLERY] ; a BuildingType registered in [BuildingTypes]
BarrelAnimIsVoxel=yes
VoxelBarrelOffsetToBuildingPivotPoint=4,2,3 ; measured from the TurretAnimX and TurretAnimY point
VoxelBarrelOffsetToRotatePivotPoint=2,0,0
VoxelBarrelOffsetToPitchPivotPoint=15,0,-8
VoxelBarrelOffsetToBarrelEnd=350,75,0
```

The barrel model is drawn with the three pivot offsets in voxel model units, but shots start from a point that uses the same numbers as leptons, 256 to a cell. A pivot offset therefore moves the drawn barrel farther than it moves the shots. [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/) moves only the shots, so it is in leptons alone.

When the building's art entry sets [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/), shots start from that offset, and the barrel offsets do not move them. A building that also sets [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) draws its barrel without these offsets, as [`BarrelAnimIsVoxel`](/keys/barrelanimisvoxel/) explains.

A value that does not begin with three whole numbers separated by commas, such as `4,2` or `4.5,2,3`, is ignored. The building keeps the offset it had before that line was read. Text after the third number is dropped, so `4,2,3,9` reads as `4,2,3`.
