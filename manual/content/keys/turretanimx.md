---
key: TurretAnimX
summary: The horizontal screen offset from a building's artwork to its turret.
see_also: ["TurretAnimY", "TurretAnim", "TurretAnimIsVoxel", "TurretAnimYSort", "TurretAnimZAdjust"]
when_omitted:
  kind: value
  value: "0"
---

`TurretAnimX` moves a building's turret to the right, or to the left with a negative value. The offset is in screen pixels, measured from the point the building's artwork is drawn at. It places the turret animation, or the voxel turret or voxel barrel on a building drawn with one.

```ini title="rules.ini"
[MYTOWER] ; a BuildingType registered in [BuildingTypes]
TurretAnim=MYTOWER_A ; an AnimType registered in [Animations]
TurretAnimX=-2
TurretAnimY=10 ; the turret sits two pixels left of the draw point and ten below it
```

The offset also moves the point the building aims from. The engine projects it onto the ground and measures the direction to the target from there, not from the building's center.

On a [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) or [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building, the offset moves the point shots start from as well. A turret drawn from an animation fires from the point its firing offsets give, and this key does not move it.

A [`PrimaryFirePixelOffset`](/keys/primaryfirepixeloffset/) in the building's art entry replaces this offset for turning toward the target and for where shots start. A building whose primary weapon has [`IsLaser=yes`](/keys/islaser/) still elevates its barrel from the point `TurretAnimX` and [`TurretAnimY`](/keys/turretanimy/) give.

A positive value can change which objects the turret animation is drawn over. The animation is placed on the ground, so a shift to the right also moves it back in the draw order, and it can fall behind objects it used to cover. A shift to the left moves it forward. [`TurretAnimYSort`](/keys/turretanimysort/) corrects the draw order without moving the artwork.
