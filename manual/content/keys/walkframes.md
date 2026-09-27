---
key: WalkFrames
summary: The number of frames in one facing's walking animation of a shape-drawn vehicle.
see_also: ["StartWalkFrame", "Facings", "StandingFrames", "WalkRate", "Turret"]
when_omitted:
  kind: value
  value: "12"
---

A moving vehicle loops through the walk run for its facing, one frame per step. [`WalkRate`](/keys/walkrate/) sets how often it steps. The runs for all its [`Facings`](/keys/facings/) sit end to end from [`StartWalkFrame`](/keys/startwalkframe/), so this value is also the distance from one facing's run to the next and must match the artwork.

A vehicle with no standing frames also rests on these runs ([`StandingFrames`](/keys/standingframes/) explains).

```ini title="art.ini"
[MMCH] ; the Image ID of the stock Titan
Voxel=no
WalkFrames=15 ; eight runs of 15, frames 0-119
```

This value also sets where the turret frames of a shape-drawn [`Turret=yes`](/keys/turret/) vehicle start by default: at `8 × WalkFrames`, frame 120 in the fragment above. [`StartTurretFrame`](/keys/startturretframe/) explains when to move them.

:::danger[Keep WalkFrames between 1 and 127]
`WalkFrames=0` crashes the game with a division by zero as soon as a moving shape-drawn vehicle of this type is drawn on screen. The value is stored in a single signed byte, so larger values wrap around: `256` stores as `0`, and `128` to `255` store as negative numbers that lay the facing runs out backward from `StartWalkFrame`.
:::
