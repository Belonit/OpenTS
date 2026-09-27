---
key: WaterSet
summary: Fourteen-tile set of open water.
see_also: [ShorePieces, ClearTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

A cell holding any of the set's fourteen tiles is open water. Open water, [`ShorePieces`](/keys/shorepieces/) tiles and the four waterfall sets together count as holding water, and a transport vehicle standing on any of them refuses to take on a passenger.

The set's first tile is plain open water. [`Fill=Water`](/keys/fill/) starts every cell of a map with this tile.

The random map generator lays lakes, rivers and the pools around a waterfall from the set's first six tiles, picked at random. When it floods the narrow strips of land between stretches of water, it writes the set's first tile. It checks each of a cell's eight neighbors for open water when it chooses the shore piece for that cell.

In a theater with ice growth, the same fourteen tiles count as water when ice breaks and when ice edge pieces are chosen. [`Ice1Set`](/keys/ice1set/) covers those rules.

:::caution[Resolve WaterSet in every theater]
None of the water tests above checks that the role resolved. With it unresolved, each one counts the theater's first thirteen tiles as open water. When clear ground is among those tiles, a transport standing on plain ground refuses its passengers.
:::
