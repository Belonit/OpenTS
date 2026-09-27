---
key: ClearToRoughLat
summary: Tile set holding the sixteen blend pieces laid where rough ground meets other terrain.
see_also: [RoughTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

A LAT set is sixteen tiles of blend art that keep one kind of ground from meeting another along a hard square edge. Rough, sand, green, pavement, crystal, swamp and blue mold ground each pair one plain ground tile with one LAT set. This page describes the blending rule that all seven share. [Theater control files](/formats/theater-control/) explains how a `[General]` role is resolved to a tile.

A cell blends when it holds its family's plain ground tile or one of the family's sixteen LAT tiles. The engine repeats the check whenever it recalculates the cell's terrain.

The piece a cell gets depends on which of its four edge neighbors are foreign, meaning they hold neither the plain ground tile nor one of the LAT tiles. Each foreign neighbor adds a value: 1 for north, 2 for east, 4 for south and 8 for west. The total is the piece's position in the LAT set, counted from 0. For example, a rough cell whose east and south neighbors are not rough takes the piece at position 6. A cell with no foreign neighbor gets the plain ground tile back, so position 0 is never chosen and the blend art occupies positions 1 through 15.

The families blend one after another on each cell, in the order rough, sand, green, pavement, crystal, swamp, blue mold. Each family sees the tile that the families before it chose.

For rough ground, the only tiles that count as rough are the plain [`RoughTile`](/keys/roughtile/) tile and the sixteen tiles here. Rough ground therefore blends against pavement, water and cliffs alike.

:::caution[Resolve the LAT set whenever its plain ground tile resolves]
Sand, green and pavement are not blended when their LAT set is unresolved. Rough, crystal, swamp and blue mold still blend a cell that holds their plain ground tile. Such a cell gets the theater's tile at the total minus one, counting every tile the theater loaded from 0. That is one of the theater's first fifteen tiles, not blend art.
:::
