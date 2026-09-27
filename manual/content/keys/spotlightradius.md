---
key: SpotlightRadius
summary: Base radius, in leptons, within which a spotlight notices an intruder.
see_also: [SpotlightLocationRadius, SpotlightMovementRadius, HasSpotlight, "system:power"]
when_omitted:
  kind: value
  value: "175"
---

`SpotlightRadius` is the radius at which a spotlight detects intruders before it widens. A beam closer to its structure than [`SpotlightLocationRadius`](/keys/spotlightlocationradius/) detects at exactly this radius. Farther out, the radius grows by about seven and a half leptons for each sweep stage the beam has reached. A stage is a tenth of the gap between `SpotlightLocationRadius` and [`SpotlightMovementRadius`](/keys/spotlightmovementradius/). Only a structure whose type sets [`HasSpotlight=yes`](/keys/hasspotlight/) has a beam.

```ini title="rules.ini"
[General]
SpotlightRadius=256  ; one cell
```

The detection radius also sets how far apart the beam's two glowing edges spread where they meet the pool of light, so a beam that detects farther looks broader. When the detection radius is larger than the beam's distance from its structure, the edges are not drawn.

Detection only matters to triggers. A sweeping beam whose structure has a tag springs the [Enemy In Spotlight...](/mapping/events/tevent-enemy-in-spotlight/) and [Enemy In Spotlight... (repeating)](/mapping/events/tevent-enemy-in-spotlight-repeating/) events when an infantry unit or vehicle that is not allied to the structure's owner stands within the detection radius plus 30 leptons. Only the nine cells around the beam are searched, so a radius that reaches past them catches nobody farther out.

A beam set to circle its structure never springs these events. A following beam springs them only on the frame it loses its target and goes back to sweeping. [Fields, fences and lights](/systems/power/#fields-fences-and-lights) covers the power the structure needs for its beam to be drawn and to detect.

:::caution[The pool of light on the ground keeps the built-in size]
The images for the pool of light are built when the game starts, before any rules file is read, so they always use the built-in `175`. A value set in `[General]` changes the detection radius and the spread of the beam's edges only.
:::
