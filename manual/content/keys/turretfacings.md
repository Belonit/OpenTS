---
key: TurretFacings
summary: The number of facings a shape-drawn vehicle's turret artwork is cut into.
see_also: ["StartTurretFrame", "Facings", "Turret", "WalkFrames"]
when_omitted:
  kind: value
  value: "32"
---

Only a [`Turret=yes`](/keys/turret/) vehicle drawn from shape artwork uses this value. It is independent of the hull's [`Facings`](/keys/facings/). Stock art never sets `TurretFacings`, so the stock Titan's turret has the default 32 frames.

Use `8`, `16`, `32` or `64`. The turret then shows the frame for its heading rounded to that many compass points. The first frame faces northwest, and the frames after it turn clockwise. With any other value, the turret always shows the first frame, whichever way it aims.

```ini title="art.ini"
[MYTANK] ; the Image ID of a shape-drawn UnitType that sets Turret=yes in rules.ini
Facings=8        ; eight body facings
WalkFrames=15
TurretFacings=16 ; 16 turret frames, from frame 120 by default
```

[`StartTurretFrame`](/keys/startturretframe/) sets the frame the turret frames start at.
