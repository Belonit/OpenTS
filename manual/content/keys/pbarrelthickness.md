---
key: PBarrelThickness
summary: Raises the point the first weapon's barrel pivots about.
see_also: ["PrimaryFireFLH", "PBarrelLength", "Elite", "SBarrelThickness"]
when_omitted:
  kind: value
  value: "0"
---

The barrel pivots this many leptons, 256 to a cell, above the mounting point that [`PrimaryFireFLH`](/keys/primaryfireflh/) sets. The pivot is raised before the barrel is pitched, so the muzzle rises by the same amount at every elevation. [`PBarrelLength`](/keys/pbarrellength/) then measures along the barrel from the raised pivot.

```ini title="art.ini"
[MYTANK] ; the Image ID of a UnitType
PrimaryFireFLH=100,0,60
PBarrelLength=80
PBarrelThickness=12 ; lifts the muzzle onto the barrel's centerline
```

The weapon's fire animation, laser beam, sonic wave and attached particle systems start at the muzzle. A structure that sets [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) or [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) takes its firing point from that setting instead, and ignores this one. The projectile starts at the muzzle only for infantry. An aircraft, structure or vehicle creates it at the mounting point, which this setting does not raise.

The [`Elite`](/keys/elite/) weapon slot uses this same setting, so an elite weapon fires from the same point as the weapon it replaces.
