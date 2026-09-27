---
key: VoxelBarrelOffsetToBarrelEnd
summary: Where a building with a voxel barrel creates its shots.
see_also: ["BarrelAnimIsVoxel", "VoxelBarrelScale", "VoxelBarrelOffsetToPitchPivotPoint", "PrimaryFireFLH", "Burst"]
when_omitted:
  kind: value
  value: "0,0,0"
---

`VoxelBarrelOffsetToBarrelEnd` sets where a [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building's shots start: the end of its barrel. The projectile is created there, the firing solution is measured from there, and the fire animation and laser beam appear there. It replaces the positions that [`PrimaryFireFLH`](/keys/primaryfireflh/) gives other buildings.

The value is three whole numbers, `X,Y,Z`, in leptons, 256 to a cell. They are measured from the point where the barrel model is hung, which [`VoxelBarrelOffsetToBuildingPivotPoint`](/keys/voxelbarreloffsettobuildingpivotpoint/), [`VoxelBarrelOffsetToRotatePivotPoint`](/keys/voxelbarreloffsettorotatepivotpoint/) and [`VoxelBarrelOffsetToPitchPivotPoint`](/keys/voxelbarreloffsettopitchpivotpoint/) set together. The offset turns and elevates with the barrel:

- `X` runs out along the barrel.
- `Y` runs to the barrel's left.
- `Z` runs at right angles to both.

[`VoxelBarrelScale`](/keys/voxelbarrelscale/) multiplies all three, so a barrel drawn smaller also fires from closer in. [`TurretAnimX`](/keys/turretanimx/) and [`TurretAnimY`](/keys/turretanimy/) move the point along with the barrel. Unlike the three pivot offsets, this offset does not change how the barrel is drawn.

```ini title="rules.ini"
[MYARTILLERY] ; a BuildingType registered in [BuildingTypes]
BarrelAnimIsVoxel=yes
VoxelBarrelScale=.75
VoxelBarrelOffsetToBarrelEnd=350,75,0 ; at .75 scale, the shot starts 262 leptons along the barrel
```

A [`Burst`](/keys/burst/) weapon alternates between two barrels. The first shot of a burst uses `Y` as written and the second uses `-Y`. A third shot and any after it start on the barrel's center line, at `Y` = `0`.

A [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) in the building's art entry takes precedence over this key.

:::caution[Set this offset on every barrel building]
A `BarrelAnimIsVoxel=yes` building that leaves this offset at `0,0,0` creates its shots where the barrel is hung, not at its end. A value that is not three whole numbers is ignored, and the earlier value stays in place.
:::
