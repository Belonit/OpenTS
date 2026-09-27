---
key: BarrelAnimIsVoxel
summary: Draws a building's gun barrel from a voxel model over its turret animation.
see_also: ["VoxelBarrelFile", "VoxelBarrelScale", "VoxelBarrelOffsetToBarrelEnd", "TurretAnimIsVoxel", "TurretAnim", "PrimaryFireFLH"]
when_omitted:
  kind: value
  value: "no"
---

`BarrelAnimIsVoxel=yes` draws a building's gun barrel as a voxel model over its turret animation. The turret itself stays an ordinary animation, named by [`TurretAnim`](/keys/turretanim/). [`VoxelBarrelFile`](/keys/voxelbarrelfile/) names the barrel model, unless the `TurretAnim` name yields a barrel name of its own, as that page explains.

```ini title="rules.ini"
[MYARTILLERY] ; a BuildingType registered in [BuildingTypes]
Turret=yes
TurretAnim=MYART_A ; an AnimType registered in [Animations]
BarrelAnimIsVoxel=yes
VoxelBarrelFile=MYARTBAR
VoxelBarrelOffsetToBuildingPivotPoint=4,2,3
VoxelBarrelOffsetToRotatePivotPoint=2,0,0
VoxelBarrelOffsetToPitchPivotPoint=15,0,-8
VoxelBarrelOffsetToBarrelEnd=350,75,0
```

The four `VoxelBarrelOffset…` keys and [`VoxelBarrelScale`](/keys/voxelbarrelscale/) place the barrel on the building. Each frame, the barrel turns with the gun's facing and tilts to the barrel's current pitch.

## Draw order

The building draws the turret animation and the barrel together, so they keep a consistent order as the gun turns. The barrel is drawn over the animation while the gun points anywhere from north-east round through south to south-west, and under it for the rest of the circle. The barrel uses a fixed depth bias; [`TurretAnimZAdjust`](/keys/turretanimzadjust/) does not move it.

Neither the barrel nor the turret animation is drawn while the building's buildup plays, or once its deconstruction is past the first frame.

## Where shots start

Shots leave from the end of the barrel, which [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/) sets, in place of the position [`PrimaryFireFLH`](/keys/primaryfireflh/) would give. [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) still takes precedence when the art entry sets it.

:::caution[Do not combine with TurretAnimIsVoxel]
A building that also sets [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) is drawn as a voxel turret. Its barrel is placed by `PrimaryFireFLH`, plus [`TurretOffset`](/keys/turretoffset/) when the `TurretAnim` name loads a turret model, and none of the `VoxelBarrelOffset…` keys apply to the drawing. Its shots still leave from the barrel end those keys set, so the drawn barrel and the point the shots leave from no longer match.
:::
