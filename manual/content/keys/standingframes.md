---
key: StandingFrames
summary: The number of frames in one facing's standing artwork of a shape-drawn vehicle.
see_also: ["StartStandFrame", "WalkFrames", "FiringFrames", "Facings"]
when_omitted:
  kind: computed
  note: 1 for a vehicle whose FiringFrames is above 0, and 0 otherwise.
---
The standing artwork is what a vehicle shows while it stands still in its cell and is neither firing nor dying.

At `0` the vehicle has no standing artwork, and it is drawn from the first frame of its facing's walk run instead. At any other value it is drawn at frame [`StartStandFrame`](/keys/startstandframe/) plus its facing number times this count. The count is therefore also the spacing between one facing's standing run and the next.

The count is stored in a single signed byte, so it wraps every 256: `128` to `255` store as negative numbers and `256` stores as `0`. A negative count still selects the standing run, but each facing after the first is then drawn from a frame before `StartStandFrame`.

On a [`Turret=yes`](/keys/turret/) vehicle with firing frames, the defaults collide. The default eight facings and one standing frame put the default [`StartStandFrame`](/keys/startstandframe/) at `8 × WalkFrames`, the same frame where the turret frames start unless [`StartTurretFrame`](/keys/startturretframe/) moves them. The engine does not separate them, so a resting body is drawn from the turret's frames with the turret drawn on top. Set `StartStandFrame` to give such a vehicle a separate standing frame.

```ini title="art.ini"
[REAPER] ; the Image ID of the stock Cyborg Reaper, which has no turret frames to collide with
Facings=8
StandingFrames=1
StartStandFrame=0 ; frames 0-7
WalkFrames=12
StartWalkFrame=8  ; the walk block follows the standing frames, frames 8-103
```

:::caution[The standing artwork never animates]
Only the first frame of a facing's standing run is ever drawn. A count above `1` reserves frames the vehicle never shows, and it pushes the default [`StartFiringFrame`](/keys/startfiringframe/) further into the file.
:::
