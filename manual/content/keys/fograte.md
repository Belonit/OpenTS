---
key: FogRate
summary: Game minutes between fog of war regrowth passes.
see_also: ["system:map-visibility", ShroudRate]
when_omitted:
  kind: value
  value: ".05"
---

```ini title="rules.ini"
[AudioVisual]
FogRate=.1 ; a regrowth pass every 90 frames
```

A game minute is 900 frames, so the default runs a regrowth pass every 45 frames. A larger value lets uncovered ground stay clear longer. `FogRate=0` stops the fog from ever closing back in, so ground once uncovered stays clear.

Passes run only while fog of war is on for the game; [`FogOfWar`](/keys/fogofwar/) and the game options decide that. [Fog regrowth](/systems/map-visibility/#fog-regrowth) covers when the first pass runs and what one pass does.
