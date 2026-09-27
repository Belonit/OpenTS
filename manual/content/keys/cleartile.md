---
key: ClearTile
summary: Tile set holding a theater's plain clear ground, used as the substitute for a cell that has no tile.
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

The set's first tile is plain clear ground. It stands in for any cell that has no tile: such a cell is drawn with it and takes its map preview and radar colors from it.

Two other paths write this tile into cells:

- When an explosion craters the ground, or the random map generator reshapes it, each reshaped cell that comes out flat gets this tile.
- A map whose [`Fill`](/keys/fill/) is absent or anything other than `Water` starts with every cell set to this tile. The `Fill` page explains why that tile can come from the previously loaded theater.

:::caution[Keep this role on tile set 0]
The engine's test for clear ground does not read this role. It accepts a cell with no tile and the theater's first tile, the one at index 0, and the random map generator lays that first tile directly as its clear ground. If this role names any other tile set, the generator does not treat cells holding this tile as clear ground.
:::
