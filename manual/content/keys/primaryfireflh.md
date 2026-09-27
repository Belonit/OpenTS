---
key: PrimaryFireFLH
summary: The offset from an object's center that its first weapon fires from.
see_also: ["Primary", "Elite", "PBarrelLength", "PBarrelThickness", "TurretOffset", "SecondaryFireFLH"]
when_omitted:
  kind: value
  value: 0,0,0
---

The value is three whole numbers, `X,Y,Z`, in leptons (256 to a cell). The offset turns with the gun as the object aims:

- `X` runs forward, in the direction the gun faces.
- `Y` runs sideways, with positive values to the gun's left.
- `Z` runs upward.

```ini title="art.ini"
[MYTANK] ; the Image ID of a UnitType
PrimaryFireFLH=100,0,60 ; a bit under half a cell forward, 60 leptons up
```

The gun's heading depends on the kind of object. [Firing geometry](/systems/firing-geometry/#the-mounting-and-the-muzzle) lists it for each.

## The mounting and the muzzle

The offset places two points, and [Firing geometry](/systems/firing-geometry/#what-each-part-of-a-shot-reads) lists which part of a shot uses each:

- The **mounting** is where the projectile is created and where its aim is measured from. It is this offset with [`TurretOffset`](/keys/turretoffset/) added to `X`. It stays in place as the barrel elevates. On a vehicle or aircraft it also tilts with the body on slopes and in flight.
- The **muzzle** is where the firing animation, laser beam, sonic wave and attached particle systems appear. It starts from the same offset but does not tilt with the body. It rises by [`PBarrelThickness`](/keys/pbarrelthickness/), then extends [`PBarrelLength`](/keys/pbarrellength/) along the elevated barrel.

An infantry type has no separate mounting: its projectile starts at the muzzle, so [`PBarrelThickness`](/keys/pbarrelthickness/) and [`PBarrelLength`](/keys/pbarrellength/) move its projectile as well as its effects.

`X` and `Z` also position a drawn voxel barrel, including the point it pivots around as it elevates. Changing this offset can therefore move the barrel artwork as well as the shot.

## Burst weapons

`Y` is reversed on every second shot of a [`Burst`](/keys/burst/) weapon. A nonzero `Y` therefore gives a burst weapon two mountings, one on each side of the centerline. [How a burst alternates muzzles](/systems/firing-geometry/#how-a-burst-alternates-muzzles) covers the order and its exceptions.

## Other slots and overrides

The elite weapon slot has no offset keys of its own. It uses `PrimaryFireFLH`, `PBarrelLength` and `PBarrelThickness`, so an [`Elite`](/keys/elite/) weapon fires from the same point as the weapon it replaces.

Two structure settings replace this offset for every weapon slot. If both are set, the first one listed applies:

- A [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) other than `65535,65535` pins both points to that screen offset.
- A [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) structure takes both points from [`VoxelBarrelOffsetToBarrelEnd`](/keys/voxelbarreloffsettobarrelend/).

Otherwise, a structure whose turret is a voxel adds the turret animation's screen offset to both points.
