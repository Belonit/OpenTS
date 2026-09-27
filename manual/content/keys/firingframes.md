---
key: FiringFrames
summary: The number of frames in one facing's firing animation of a shape-drawn vehicle.
see_also: ["StartFiringFrame", "FiringSyncFrame1", "FiringSyncFrame2", "StandingFrames", "Facings"]
when_omitted:
  kind: value
  value: "0"
---

At `0` the vehicle has no firing animation, and its shots are never held back to line up with one.

The value also changes two other defaults in the same section:

- At `0`, [`StandingFrames`](/keys/standingframes/) defaults to `0`, and [`Facings`](/keys/facings/) defaults to `1` unless the vehicle has [`Turret=yes`](/keys/turret/).
- Above `0`, `StandingFrames` defaults to `1` and `Facings` to `8`.

The animation plays once each time the vehicle fires, for twice this many game frames: each frame is held for two game frames. `FiringFrames=6` lasts 12 game frames, a little under a second. The run plays backward, from its last frame to its first. A moving vehicle shows its walk frames instead.

For each facing the run starts at [`StartFiringFrame`](/keys/startfiringframe/) plus the facing number times this count.

```ini title="art.ini"
[SMECH] ; the Image ID of the stock Wolverine
Voxel=no
WalkFrames=12
FiringFrames=4 ; eight runs of 4, starting at frame 8 × (1 + 12) = 104
```

By default the round leaves when the animation starts. [`FiringSyncFrame1`](/keys/firingsyncframe1/) and [`FiringSyncFrame2`](/keys/firingsyncframe2/) release the round at a chosen point in the animation instead.
