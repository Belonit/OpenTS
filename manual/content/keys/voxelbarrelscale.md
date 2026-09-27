---
key: VoxelBarrelScale
summary: The size a building's voxel barrel is drawn at, as a multiple of the model's own.
see_also: ["BarrelAnimIsVoxel", "VoxelBarrelFile", "VoxelBarrelOffsetToBarrelEnd"]
when_omitted:
  kind: value
  value: "1.0"
---

The scale resizes the barrel model about the point the three pivot offsets place it at, so the barrel's mount does not move. Those pivot offsets keep their length whatever the scale.

The shots scale with the barrel. [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/) is multiplied by the same value, so a barrel drawn at three quarters size also fires from three quarters of the distance out. The scale does not move the shots when the building's art entry sets [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/), because shots then start from that offset.

```ini title="rules.ini"
[MYARTILLERY] ; a BuildingType registered in [BuildingTypes]
BarrelAnimIsVoxel=yes
VoxelBarrelFile=MYARTBAR
VoxelBarrelScale=.75 ; three quarters of the size the model was built at
```

Only a [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building uses the setting.
