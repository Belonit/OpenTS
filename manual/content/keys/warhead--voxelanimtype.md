---
key: Warhead
scope: voxelanimtype
label: Voxel debris warhead
see_also: ["Damage", "DamageRadius", "ExpireAnim"]
when_omitted:
  kind: value
  value: none
---

The warhead a voxel debris piece deals its [`Damage`](/keys/damage/#scope-voxelanimtype) through. The warhead's armor multipliers and its [`Spread`](/keys/spread/#scope-warheadtype) decide how much each object takes. A piece deals damage at two points in its life.

- **Each bounce on land.** Every object in the cell the piece strikes takes the damage if it stands within [`DamageRadius`](/keys/damageradius/#scope-voxelanimtype) of the landing point. A bounce in water ends the piece's life instead.
- **The end of its life.** The piece explodes where it comes to rest or where its time runs out, unless that point is low over water. This blast happens only when the type also names an [`ExpireAnim`](/keys/expireanim/#scope-voxelanimtype). It is an ordinary explosion that reaches objects in the surrounding cells, and `DamageRadius` does not limit it.

If the warhead sets [`Bright=yes`](/keys/bright/#scope-warheadtype), the end-of-life blast also lights up the ground around it. A bounce never does.

A piece with no warhead deals no damage at either point. It still bounces and plays its animations and sounds, and cratering and Tiberium seeding happen as they would with a warhead.

`Warhead=none` and `Warhead=<none>` both clear the setting. A name that matches no warhead is not rejected. It creates a new warhead of that name, so a misspelled name produces a warhead with no section of its own and every setting at its default.
