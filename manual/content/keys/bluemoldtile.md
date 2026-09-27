---
key: BlueMoldTile
summary: Tile set whose first tile is a theater's plain blue mold ground.
see_also: [ClearToBlueMoldLat]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

The set's first tile is the plain blue mold ground. Only that tile is used. On any map, a mold cell whose four orthogonal neighbors are all mold shows it; a cell at the edge of a patch shows a [`ClearToBlueMoldLat`](/keys/cleartobluemoldlat/) transition piece instead.

The random map generator lays blue mold only on mutated maps, a biome it offers only with Firestorm and builds in the temperate theater.

Each patch starts on a clear spot and spreads only into cells whose four orthogonal neighbors are all clear ground or mold. The cell's own tile is not checked, so mold can cover whatever tile was there.

After laying a patch, the generator makes up to four random picks among its plain mold cells. A picked cell with no terrain object and no overlay gets one of the terrain objects `FONA01` to `FONA05` three times in four, and a large Tiberium overlay otherwise.
