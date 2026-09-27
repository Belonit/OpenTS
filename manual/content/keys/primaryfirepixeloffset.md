---
key: PrimaryFirePixelOffset
summary: The screen offset a building's shots leave from, in place of its firing offsets.
see_also: ["PrimaryFireFLH", "SecondaryFirePixelOffset", "BarrelAnimIsVoxel", "TurretAnimX", "Primary"]
when_omitted:
  kind: value
  value: 65535,65535
---

Two whole numbers, `X,Y`, in screen pixels from the point the building's artwork is drawn at. A positive `X` moves right and a positive `Y` moves down.

Any pair other than `65535,65535` places three points of the building at that offset:

- the mounting, where the projectile is created and the firing solution is measured from;
- the muzzle, where the fire animation and beam appear;
- the point the building aims from when it turns to face a target, which is measured from the building's center instead of its draw point.

The offset applies to every weapon the building fires, not only the first.

```ini title="art.ini"
[MYOBELISK] ; the Image ID of a BuildingType
PrimaryFirePixelOffset=2,-38 ; the beam leaves 38 pixels above the draw point
```

The offset does not raise or lower the shot. It moves the shot's starting point across the map, at the building's height, to the spot that is drawn that many pixels from the draw point. A negative `Y` therefore starts the shot on the map north of the building.

The offset also takes precedence over the barrel. A [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) building with this set fires from the fixed screen point, not from the end of its barrel. [`PrimaryFireFLH`](/keys/primaryfireflh/) covers the offsets it displaces.

:::caution[Write both numbers]
Only the exact pair `65535,65535` leaves the offset off. A value with fewer than two whole numbers is rejected whole, so the offset also stays off.
:::
