---
key: TurretOffset
summary: Moves an object's turret forward from its center along the centerline.
see_also: ["PrimaryFireFLH", "SecondaryFireFLH", "Turret", "Voxel"]
when_omitted:
  kind: value
  value: "0"
---

The distance is in leptons, 256 to a cell. A positive value moves the turret toward the front, and a negative value moves it back.

```ini title="art.ini"
[MYTANK] ; the Image ID of a UnitType
TurretOffset=-40 ; the turret sits behind the middle of the hull
```

The offset moves where shots come from. It is added to the forward (`X`) component of every weapon slot's firing offset, so neither [`PrimaryFireFLH`](/keys/primaryfireflh/) nor [`SecondaryFireFLH`](/keys/secondaryfireflh/) has to repeat it. Both the point a projectile starts from and the muzzle move.

The offset also moves the drawn turret:

- A vehicle's voxel turret and barrel are drawn this far along the hull's heading, and turn about that point. The turret therefore pivots where its artwork sits, not at the middle of the hull.
- A structure's voxel turret ([`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/)) is drawn this far along the turret's heading, which matches where it fires from.
- An aircraft or an infantryman has no turret artwork, so only its firing offsets move.

:::caution[A vehicle's shots and its drawn turret can separate]
A vehicle's firing offset is moved along the turret's heading, but its drawn turret is moved along the hull's heading. The two match while the turret points the same way as the hull, and drift apart as the turret turns away from it.
:::
