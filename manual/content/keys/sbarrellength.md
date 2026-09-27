---
key: SBarrelLength
summary: How far out along the second weapon's barrel its muzzle sits.
see_also: ["SecondaryFireFLH", "SBarrelThickness", "PBarrelLength"]
when_omitted:
  kind: value
  value: "0"
---

The distance is in leptons, 256 to a cell. It is measured along the barrel after the barrel has been pitched, so the muzzle swings up and down with the gun while the mounting point stays put. Only the second weapon slot uses it.

```ini title="art.ini"
[MYTANK] ; the Image ID of a UnitType
SecondaryFireFLH=100,0,20
SBarrelLength=40 ; the second weapon's muzzle sits 40 leptons out along its barrel
```

The muzzle places the firing animation, a laser beam, and the start of a sonic wave or an attached particle system. Where the projectile is created depends on the object:

- An AircraftType, BuildingType or UnitType creates it at the mounting point that [`SecondaryFireFLH`](/keys/secondaryfireflh/) and [`TurretOffset`](/keys/turretoffset/) fix, which this key does not move.
- An InfantryType creates it at the muzzle, so this key moves the projectile too.

A value above `0` also advances the second weapon's projectile up to two steps along its flight as soon as it is fired. The second step is skipped if the first ends the projectile. Laser weapons and [`Inviso=yes`](/keys/inviso/) projectiles are not advanced.

A structure that takes its firing points from [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/) or [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) ignores this key, as the [`SecondaryFireFLH`](/keys/secondaryfireflh/) page describes.
