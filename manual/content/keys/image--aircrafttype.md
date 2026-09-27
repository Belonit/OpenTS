---
key: Image
scope: aircrafttype
label: Image ID
see_also: [Voxel, Theater, NewTheater]
when_omitted:
  kind: computed
  note: Uses the ObjectType ID as the Image ID. A BulletType uses it only for its first shape and for Voxel, Theater and NewTheater.
---

The Image ID names both the type's artwork file and the `art.ini` section its art settings are read from. Two types given the same Image ID therefore share both the file and the art settings.

[`Voxel=`](/keys/voxel/) in that section decides whether most types load `<Image ID>.VXL` in place of `<Image ID>.SHP`. A BuildingType, and a BulletType without [`Inviso=yes`](/keys/inviso/), load the shape either way, and a VoxelAnimType always loads the `.VXL`. [`Theater=`](/keys/theater/#scope-aircrafttype) and [`NewTheater=`](/keys/newtheater/#scope-aircrafttype), read from the same section, can change the shape file's name for the current theater.

If the file is missing, the type has no artwork. The engine does not substitute another file.

Set `Image=` on every BulletType that is drawn. A BulletType without it reads none of [`Trailer`](/keys/trailer/), [`Rotates`](/keys/rotates/), [`AnimLow`](/keys/animlow/), [`AnimHigh`](/keys/animhigh/), [`AnimRate`](/keys/animrate/) or [`AnimPalette`](/keys/animpalette/). In a new game it draws `<BulletType ID>.SHP` if it is not a voxel projectile, and a voxel projectile gets no model. After a saved game loads, it has no shape either.

:::danger[Give every VoxelAnimType its `.VXL` file]
A VoxelAnimType with its own section in the rules loads `<Image ID>.VXL` when that section is read, unless it borrows another type's model through [`ShareBodyData`](/keys/sharebodydata/), [`ShareTurretData`](/keys/shareturretdata/) or [`ShareBarrelData`](/keys/sharebarreldata/). If that file is missing, the game crashes the first time an animation of that type is drawn on screen.

A VoxelAnimType that is named elsewhere but has no section of its own has no model and draws nothing. Other voxel types, such as an aircraft, discard a model that fails to load, so they are left with none and avoid this crash.
:::
