---
key: VoxelBarrelFile
summary: The voxel model a building's gun barrel is drawn from.
see_also: ["BarrelAnimIsVoxel", "TurretAnim", "VoxelBarrelScale", "TurretAnimIsVoxel"]
when_omitted:
  kind: value
  value: ""
---

`VoxelBarrelFile` names the voxel model a [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building draws as its barrel. Write the file name without its extension: the engine loads `<name>.VXL` with `<name>.HVA` beside it. At most 15 characters are kept.

```ini title="rules.ini"
[MYARTILLERY] ; a BuildingType registered in [BuildingTypes]
TurretAnim=MYART_A ; an AnimType registered in [Animations]; has no TUR
BarrelAnimIsVoxel=yes
VoxelBarrelFile=MYARTBAR ; the barrel is drawn from MYARTBAR.VXL
```

The key is used only when the [`TurretAnim`](/keys/turretanim/) name does not supply a barrel name. A `TurretAnim` name supplies one when it contains `TUR`, in any case, starting at the fifth character or later. The engine then loads the barrel from that name with `TUR` and everything after it replaced by `BARL`, and ignores this key. A `TUR` that starts within the first four characters is not found, so a name such as `TURMYART` still uses this key.

A building without `BarrelAnimIsVoxel=yes` ignores the key.
