---
key: ShorePieces
summary: Forty-two-tile set of the shoreline pieces laid between water and land.
see_also: [WaterSet]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

A cell holding any of the forty-two pieces is shore. Shore counts as ground that holds water, although it is not open [`WaterSet`](/keys/waterset/) water. This has two effects on any map, generated or not:

- A transport vehicle standing on shore refuses to take on passengers, as it does on water.
- In a theater with ice growth, the game re-dresses ice whenever ice cracks, breaks, grows or refreezes, and when the random map generator lays ice. At those times, an affected cell holding the first tile of any of the three ice sets becomes the first edge tile of [`Ice1Set`](/keys/ice1set/) if a shore cell lies on one of its four sides.

The [random map generator](/formats/map-seed/) lays the pieces along its coastlines. It picks a piece from the pattern of water across all eight neighbors of the cell that needs shore. The engine keeps three fixed values for each of the forty-two positions: where the piece is anchored relative to that cell, a group of interchangeable pieces, and a facing. A replacement set must therefore keep its pieces in the same order.

Two tests keep a generated coastline continuous. Which one applies depends on the cell a new piece would cover:

- If that cell belongs to a different [region](/systems/map-generation/#regions-cliffs-and-ramps) and already holds a tile, both tiles must be shore pieces of the same group. If they are, the existing tile stays and the new piece is laid no further; otherwise the piece is refused.
- If that cell belongs to the same region and both tiles are shore pieces, the piece is refused when the two facings point roughly away from each other, three to five steps apart.

:::caution[An unresolved role makes the theater's first tiles shore]
The shore test does not check that the role resolved. Left unresolved, it treats the theater's first forty-one tiles as shore, and those include the clear ground tile. A transport vehicle on clear ground then refuses passengers, and ice next to such ground turns to edge tiles.
:::

:::danger[Resolve this role in any theater used for random maps]
The random map generator takes each shore piece from the tile list at this role plus the piece's position, with no check that the role resolved. In a theater that omits the key, choosing the first piece reads one entry before the start of the tile list and uses it as a tile. The other pieces lay the theater's early tiles as shore. A random map is stored as a seed and rebuilt by each player at load time, so every client meets the fault, not only the machine that generated the map.
:::
