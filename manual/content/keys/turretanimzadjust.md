---
key: TurretAnimZAdjust
summary: The depth bias a building's turret art is drawn with.
see_also: ["TurretAnimYSort", "TurretAnim", "TurretAnimIsVoxel", "BarrelAnimIsVoxel"]
when_omitted:
  kind: value
  value: "0"
---

`TurretAnimZAdjust` is the depth bias of a building's turret art, in pixels. A lower value draws the art in front of what it overlaps, and a higher one behind it. Turret art usually needs a negative value so that it draws over the structure it is mounted on.

Which art the bias applies to depends on how the turret is drawn:

- A turret drawn from an animation takes the bias.
- A [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) building has no turret animation. Its voxel turret and barrel take the bias instead.
- A [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building applies the bias to its turret animation only. Its voxel barrel always uses a bias of `-21`, 21 pixels in front.

:::caution[Keep the value between -128 and 127]
The value is stored in a single signed byte. A value outside that range wraps around, so `-200` is stored as `56` and pushes the art behind the building instead of in front of it.
:::
