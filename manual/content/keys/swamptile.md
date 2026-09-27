---
key: SwampTile
summary: Nine-tile set of swamp ground, the first tile plain and the rest decorative.
see_also: [WaterToSwampLat]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

The first tile is plain swamp and the eight after it are decorative. [`WaterToSwampLat`](/keys/watertoswamplat/) blends other ground against the plain tile. A swamp blend cell whose four neighbors are all swamp or swamp blend turns back into the plain tile.

The random map generator grows swamp only on mutated-biome maps, which use the temperate theater. It writes the plain tile over each water cell a swamp spreads into. It then lays up to eight decorative tiles, each only where every cell the tile would cover still holds plain swamp.

A cell counts as swamp when it holds any of the nine tiles or a `WaterToSwampLat` piece. The generator groups swamp with water when it divides the map into [regions](/systems/map-generation/#regions-cliffs-and-ramps). With the role unresolved, no cell counts as swamp.

:::danger[Resolve this role in a theater that mutated maps use]
The swamp spread does not check that the role resolved. With it unresolved, a mutated-biome map that grows swamp writes an invalid tile number into the swamp cells, and the engine later looks that number up outside the tile list. The decorative patches are taken from the theater's first eight tiles.
:::
