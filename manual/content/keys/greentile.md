---
key: GreenTile
summary: Tile set whose first tile is a theater's plain green ground.
see_also: [ClearToGreenLat]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Only the set's first tile is used. It is the plain green ground that [`ClearToGreenLat`](/keys/cleartogreenlat/) blends against, and a green transition cell whose four neighbors are all green ground or green transitions turns back into this tile.

The [random map generator](/systems/map-generation/) paints this tile in patches over open clear ground on temperate and mutated maps. Each cell rolls for green before it rolls for rough ground or sand, so a cell that starts a green patch never starts either of the others. The chance grows with the map's vegetation setting. Desert, tundra and taiga maps never get green patches.
