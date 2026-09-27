---
key: TurretAnimIsVoxel
summary: Draws a building's turret from voxel models named by TurretAnim.
see_also: ["TurretAnim", "BarrelAnimIsVoxel", "TurretNotExportedOnGround", "TurretAnimZAdjust", "TurretOffset", "PrimaryFireFLH"]
when_omitted:
  kind: value
  value: "no"
---

`TurretAnimIsVoxel=yes` draws the building's turret from the voxel models that [`TurretAnim`](/keys/turretanim/) names, and no turret animation is started when construction finishes. A building whose primary weapon is [`Charges=yes`](/keys/charges/) still starts the turret animation when it begins to charge. The game then [crashes](/keys/turretanim/) unless the voxel base name is also a registered AnimType.

The models are drawn over the structure every frame, except while its build-up or sell animation plays. An [`Artillary=yes`](/keys/artillary/) structure draws them during those animations too.

```ini title="rules.ini"
[MYTOWER] ; a BuildingType registered in [BuildingTypes]
Turret=yes
TurretAnim=MYTWRTUR ; the voxel base name, not an AnimType ID
TurretAnimIsVoxel=yes
TurretAnimZAdjust=-40
```

## Placement

The models are drawn at the pixel offset that [`TurretAnimX`](/keys/turretanimx/) and [`TurretAnimY`](/keys/turretanimy/) give, and at the depth [`TurretAnimZAdjust`](/keys/turretanimzadjust/) gives. The weapon's mounting point and the point shots leave from move by the same pixel offset, added to the positions [`PrimaryFireFLH`](/keys/primaryfireflh/) gives. [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) replaces both points when it is set.

The building also sorts an eighth of a cell (32 leptons) further forward than it stands. This keeps the turret drawn over neighbors that would otherwise cover it.

When a turret model is loaded, [`TurretOffset`](/keys/turretoffset/) shifts the turret and barrel models along the turret's facing.

The barrel pitches about a point taken from `PrimaryFireFLH`; [`TurretNotExportedOnGround`](/keys/turretnotexportedonground/) covers which point.

The four barrel pivot offsets, beginning with [`VoxelBarrelOffsetToBuildingPivotPoint`](/keys/voxelbarreloffsettobuildingpivotpoint/), and [`VoxelBarrelScale`](/keys/voxelbarrelscale/) have no effect here. Only a [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building uses them.

## Aiming

A voxel turret aims exactly, where an animated turret aims to the nearest of its 32 frames:

| Behavior | Animated turret | Voxel turret |
| --- | --- | --- |
| May fire when its facing is within | 11.25 degrees (one frame) of the target | 0 degrees; it must point exactly at the target |
| Its shot leaves along | the rounded facing | the exact direction to the target |

A voxel turret that has come within 2.8125 degrees of the target snaps the rest of the way, so it can fire.
