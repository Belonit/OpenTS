---
key: RampBase
summary: Tile set holding the twenty plain ramps that carry ground between height levels.
see_also: [RampSmooth, MMRampBase, SlopeSetPieces, CliffRamps]
when_omitted:
  kind: value
  value: "-1"
  note: The role stays unresolved. Ramp shape 1 then gets tile index -1, and shapes 2 through 20 get the theater's first nineteen tiles.
---

The set holds one single-cell ramp piece for each ramp shape, in this order:

| Tiles | Ramp shapes |
| --- | --- |
| 1 to 4 | Straight ramps descending west, north, east and south |
| 5 to 8 | Outer corners, with one corner raised |
| 9 to 12 | Inner corners, with three corners raised |
| 13 to 16 | Steep ramps, with two corners raised and a third raised twice as high |
| 17 to 20 | Double ramps, with two opposite corners raised |

Directions are map directions, and map north is the upper right of the screen. The engine takes the piece for a shape by its position in the set, so pieces stored out of order give cells artwork that does not match their slope. [Theater control files](/formats/theater-control/) explains how the `[General]` value selects a set.

The engine writes pieces from this set into cells in these cases:

- Terrain deformation, from a warhead's [`Deform`](/keys/deform/) or a meteor crater set by [`CraterLevel`](/keys/craterlevel/), gives each reshaped cell the piece for its new slope.
- A [veinhole monster](/systems/veins/) that the random map generator places sinks the three-by-three block of cells around it and lines the rim with ramps.
- Whenever a cell's terrain is recalculated, including at scenario start, a cell holding one of this set's four straight ramps or a [`RampSmooth`](/keys/rampsmooth/) blend piece has its piece picked again. It gets its plain piece from this set when both neighbors along the slope also slope, and a blend piece from `RampSmooth` otherwise.
- Placing the sixth or ninth piece of [`SlopeSetPieces`](/keys/slopesetpieces/) during play replaces some of its cells with the second or first piece of this set.

The random map generator uses the same pieces when it builds slopes.

:::danger[Point RampBase at a tile set the theater loads]
A value that names no loaded set, including the first number past the last set, leaves the role unresolved, just as omitting the key does. Every path above still writes the resulting index into the cell. A west-descending ramp then gets index `-1`, which is not a tile, and the engine reads outside the theater's tile list when it uses that cell.
:::
