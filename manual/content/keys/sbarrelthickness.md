---
key: SBarrelThickness
summary: Raises the point the second weapon's barrel pivots about.
see_also: ["SecondaryFireFLH", "SBarrelLength", "PBarrelThickness"]
when_omitted:
  kind: value
  value: "0"
---

The value is in leptons, 256 to a cell. It is added to the `Z` component of [`SecondaryFireFLH`](/keys/secondaryfireflh/) before the barrel is pitched, so the barrel pivots from a higher point and the muzzle rises with it. Use it to put the pivot in the middle of the barrel artwork instead of at its base. Only the second weapon slot uses it.

```ini title="art.ini"
[MYTANK] ; the Image ID of a UnitType
SecondaryFireFLH=100,0,20
SBarrelLength=40
SBarrelThickness=8
```

The muzzle places the firing animation, a laser beam, and the start of a sonic wave or an attached particle system. Where the projectile is created depends on the object:

- An AircraftType, BuildingType or UnitType creates it at the mounting point that `SecondaryFireFLH` and [`TurretOffset`](/keys/turretoffset/) fix, which this key does not move.
- An InfantryType creates it at the muzzle, so this key moves the projectile too.

A structure that takes its firing points from [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/) or [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) ignores this key, as the [`SecondaryFireFLH`](/keys/secondaryfireflh/) page describes.
