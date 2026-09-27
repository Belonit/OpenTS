---
key: SecondaryFireFLH
summary: The offset from an object's center that its second weapon fires from.
see_also: ["Secondary", "SBarrelLength", "SBarrelThickness", "TurretOffset", "PrimaryFireFLH"]
when_omitted:
  kind: value
  value: 0,0,0
---

The three components work as they do for [`PrimaryFireFLH`](/keys/primaryfireflh/), measured from the direction the gun faces: `X` forward, `Y` to the gun's left, `Z` upward, in leptons.

```ini title="art.ini"
[MYTANK] ; the Image ID of a UnitType
PrimaryFireFLH=100,0,60
SecondaryFireFLH=100,0,20 ; the second weapon fires from lower down the hull
```

Only the second weapon slot uses this offset. The elite weapon replaces the first slot and fires from `PrimaryFireFLH`. [`SBarrelLength`](/keys/sbarrellength/) and [`SBarrelThickness`](/keys/sbarrelthickness/) turn this offset into a muzzle position, as the primary pair do for the first slot.

A structure fitted with an upgrade whose type has a [`Secondary`](/keys/secondary/) weapon fires that weapon from the upgrade type's `SecondaryFireFLH`, so the building's offset has no effect.

A sonic wave from this slot starts at its muzzle but then follows the first weapon's muzzle, as [`IsSonic`](/keys/issonic/) describes.

:::caution[Two building settings replace this offset]
A [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building takes its firing points from [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/) instead. A building with a [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) other than `65535,65535` fires from that screen offset. Either setting makes this key have no effect on that building.
:::
