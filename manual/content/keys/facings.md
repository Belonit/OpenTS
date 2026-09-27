---
key: Facings
summary: The number of facings a shape-drawn vehicle's artwork is cut into.
see_also: ["WalkFrames", "StandingFrames", "FiringFrames", "TurretFacings", "RotCount", "Voxel"]
when_omitted:
  kind: computed
  note: 8, or 1 for a vehicle that declares no firing frames and no turret.
---

Only a vehicle drawn from shape artwork is drawn in these facings. A [`Voxel=yes`](/keys/voxel/) vehicle is drawn by rotating its model, but the figure can still change how long its wreck stays on the map, as described below.

The figure does two separate jobs: it sets how many facings the vehicle is drawn in, and it multiplies the default start frames of the standing, firing and death blocks.

Use `8`, `16`, `32` or `64`. The vehicle is drawn at the nearest of that many compass directions to its heading. Facing 0 is northwest at every count, and the facings run clockwise from there. At `8`, northwest is facing 0, north is facing 1, and so on round to west at facing 7.

Any other value draws every instance at facing 0, whichever way it points.

```ini title="art.ini"
[JUGGER] ; the Image ID of the stock Juggernaut
Voxel=no
WalkFrames=15  ; blocks of 15 frames, one per facing, from frame 0
StandingFrames=0
Facings=8
```

The default [`StartStandFrame`](/keys/startstandframe/), [`StartFiringFrame`](/keys/startfiringframe/) and [`StartDeathFrame`](/keys/startdeathframe/) each multiply a per-facing frame count by this figure. A higher value moves those blocks further into the file, even when the value is not one of the four drawn counts. At `1` the blocks are laid out for a single facing.

The default [`MaxDeathCounter`](/keys/maxdeathcounter/) is built from the default `StartDeathFrame`, so for a vehicle with [`DeathFrames`](/keys/deathframes/) above `0` this figure also changes how long the wreck stays on the map. This holds for `Voxel=yes` vehicles too.

:::caution[The turret strip does not move with this figure]
A [`Turret=yes`](/keys/turret/) vehicle takes its turret frames from frame `8 × WalkFrames` whatever this figure holds. Artwork cut into more facings than 8 must start its walk block after the turret frames, or name [`StartTurretFrame`](/keys/startturretframe/).
:::
