---
key: TurretAnimYSort
summary: The bias added to where a building's turret animation falls in the draw order.
see_also: ["TurretAnimY", "TurretAnimZAdjust", "TurretAnim", "TurretAnimIsVoxel"]
when_omitted:
  kind: value
  value: "0"
---

`TurretAnimYSort` changes whether a building's turret animation is drawn over or under nearby objects, without moving it on screen. A higher value draws the animation later, over objects it would otherwise fall behind. A lower value draws it earlier. The value is in leptons and is added to the position the animation sorts by among the objects in its layer.

Use it to correct a turret moved up with a negative [`TurretAnimY`](/keys/turretanimy/) or to the right with a positive [`TurretAnimX`](/keys/turretanimx/). Either shift also moves the animation back in the draw order. `TurretAnimX` and `TurretAnimY` move the artwork itself.

The key applies only to a turret drawn as an animation that sorts on its own:

- A [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) building draws a voxel turret and has no turret animation to sort.
- A [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building draws its turret animation itself, together with the barrel, so the animation takes no separate place in the draw order.

:::caution[Keep the value between -128 and 127]
The value is stored in a single signed byte. A value outside that range wraps around, so `200` is stored as `-56` and moves the animation the other way.
:::
