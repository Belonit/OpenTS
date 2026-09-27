---
key: SandTile
summary: Tile set whose first tile is a theater's plain sand ground.
see_also: [ClearToSandLat]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Only the set's first tile is used. It is the plain sand that [`ClearToSandLat`](/keys/cleartosandlat/) blends into other ground. A sand blend cell turns back into this tile when all four of its edge neighbors are sand.

The random map generator grows sand patches only on desert maps, which use the temperate theater. Temperate and mutated maps have no sand chance. Tundra and taiga maps grow [`Rocks`](/keys/rocks/) patches instead, so the snow theater does not need this set for generated maps. [Ground cover](/systems/map-generation/#ground-cover) gives the order of the rolls.

:::danger[Set SandTile in the temperate theater]
If the role is unresolved, sand patches on desert maps are laid as tile index `-1`, which is not a tile. Blending can replace a patch's edge cells, but its inner cells keep that index. On any map, a sand blend cell whose four edge neighbors are all sand also turns into index `-1`. The engine reads outside the theater's tile list when it uses such a cell.
:::
