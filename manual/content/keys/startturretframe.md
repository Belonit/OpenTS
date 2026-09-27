---
key: StartTurretFrame
summary: The frame a shape-drawn vehicle's turret artwork begins at.
see_also: ["TurretFacings", "WalkFrames", "Facings", "Turret"]
when_omitted:
  kind: computed
  note: 8 × WalkFrames, counted from frame 0, whatever Facings holds.
---

The turret frames start at this frame, one frame for each of the vehicle's [`TurretFacings`](/keys/turretfacings/). Only a [`Turret=yes`](/keys/turret/) vehicle drawn from shape artwork draws them.

The default leaves room for exactly eight walk runs from frame 0, whatever [`Facings`](/keys/facings/) holds. It takes no account of [`StartWalkFrame`](/keys/startwalkframe/) or of the standing and firing frames. By default the turret frames therefore overlap other artwork on a vehicle that has any of these:

- more than eight facings, whose later walk runs pass the turret frames' start;
- a `StartWalkFrame` above `0`, which pushes the last walk runs past it;
- eight facings and [`FiringFrames`](/keys/firingframes/) above `0`, whose default standing or firing frames start at the same frame ([`StandingFrames`](/keys/standingframes/) explains).

To separate them, set `StartTurretFrame` to put the turret frames after the other artwork, or move the other runs after the turret frames with their start keys. The fragment below moves the walk runs.

```ini title="art.ini"
[MYTANK] ; the Image ID of a shape-drawn Turret=yes UnitType
Facings=32
WalkFrames=3
                  ; default turret frames: 24-55, after eight runs of 3
StartWalkFrame=56 ; the 32 walk runs start after them
```

Moving the walk runs moves no other default ([`StartWalkFrame`](/keys/startwalkframe/) lists them). This vehicle has no standing frames, so it rests on its walk runs and needs nothing more. Standing, firing or death frames placed after the turret frames need their start frames set.
