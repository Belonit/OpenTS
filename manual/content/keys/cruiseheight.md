---
key: CruiseHeight
summary: The height above ground a jumpjet unit levels off at once it has finished climbing.
see_also: [Climb, WobbleDeviation, FlightLevel]
when_omitted:
  kind: value
  value: "400"
---

```ini title="rules.ini"
[JumpjetControls]
CruiseHeight=500
```

The value is the flight level, in leptons with 256 to a cell, that a jumpjet climbs to after takeoff and holds while it travels or hovers. It drops below this in two cases:

- a jumpjet with no target that comes within one cell of its destination descends to three quarters of the value;
- a jumpjet with no target that reaches its destination lands.

While it travels, a jumpjet measures this height from what lies beneath it: the ground, the roof of a structure, or the deck of a bridge above that cell. Any other unit beneath it counts as a third of a cell above the ground, whatever its size. A jumpjet crossing a bridge therefore flies this far above the deck.

A moving jumpjet also looks one cell ahead. When the cell ahead is taller, it starts climbing to this value above that cell before it arrives. When the cell ahead is lower, it aims for the average of the two heights, so it flies less than this value above the cell it is over.

The same value decides which layer a jumpjet is drawn in. Between the ground and this height, it is drawn in the air layer, above ground objects. At or above this height, it is drawn in the top layer, over everything. Beneath a bridge, a jumpjet that has risen past the deck is measured from the deck for this test.

A hovering or cruising jumpjet bobs above and below its flight level by up to [`WobbleDeviation`](/keys/wobbledeviation/). At the full flight level over open ground, that bobbing is centered on the boundary between the two layers, so any nonzero deviation makes the jumpjet switch layers as it bobs.
