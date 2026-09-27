---
key: RampSmooth
summary: Tile set holding the twelve pieces that blend a straight ramp into flat ground.
see_also: [RampBase, MMRampBase, SlopeSetPieces]
when_omitted:
  kind: value
  value: "-1"
  note: The role stays unresolved. Blend piece 1 then becomes tile index -1, and pieces 2 through 12 become the theater's first eleven tiles.
---

The set holds three blend pieces for each straight ramp direction: tiles 1 to 3 for ramps descending west, 4 to 6 for north, 7 to 9 for east, and 10 to 12 for south. [Theater control files](/formats/theater-control/) explains how the `[General]` value selects a set.

Whenever a cell's terrain is recalculated, including at scenario start, the engine checks each cell holding one of the four straight ramps from [`RampBase`](/keys/rampbase/) or a piece from this set. It looks at the cell's two neighbors along the slope: the cell below it and the cell above it. A neighbor with no slope counts as flat. The ramp then takes the piece for its direction:

| Flat neighbors | Piece within the direction |
| --- | --- |
| The cell below only | First |
| The cell above only | Second |
| Both | Third |
| Neither | None; the ramp gets its plain piece from `RampBase` |

Only the four straight `RampBase` ramps are blended. Corner, steep and double ramps keep their plain pieces whatever surrounds them, and straight ramps from other sets keep their tiles.

:::danger[Point RampSmooth at a tile set the theater loads]
If this role is unresolved, blending still writes a piece index into every straight `RampBase` ramp that has a flat neighbor, on every map. The ramp gets one of the theater's first eleven tiles, and a west-descending ramp whose lower neighbor alone is flat gets index `-1`, which is not a tile. The engine reads outside the theater's tile list when it uses that cell.
:::
