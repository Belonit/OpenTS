---
key: TurretAnimY
summary: The vertical screen offset from a building's artwork to its turret.
see_also: ["TurretAnimX", "TurretAnim", "TurretAnimIsVoxel", "TurretAnimYSort", "TurretAnimZAdjust"]
when_omitted:
  kind: value
  value: "0"
---

`TurretAnimY` moves a building's turret down the screen, or up with a negative value. The offset is in screen pixels, measured from the point the building's artwork is drawn at. It places the turret animation, or the voxel turret or voxel barrel on a building drawn with one.

```ini title="rules.ini"
[MYTOWER] ; a BuildingType registered in [BuildingTypes]
TurretAnim=MYTOWER_A ; an AnimType registered in [Animations]
TurretAnimX=-2
TurretAnimY=10 ; the turret sits two pixels left of the draw point and ten below it
```

Like [`TurretAnimX`](/keys/turretanimx/), the offset also moves the point the building aims from, and on some buildings the point it fires from. `TurretAnimX` covers when.

A negative value can change which objects the turret animation is drawn over. The animation is placed on the ground, so raising it up the screen also moves it back in the draw order, and it can fall behind objects it used to cover. [`TurretAnimYSort`](/keys/turretanimysort/) moves it forward in the draw order again without moving the artwork.
