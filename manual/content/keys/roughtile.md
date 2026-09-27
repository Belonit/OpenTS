---
key: RoughTile
summary: Tile set whose first tile is a theater's plain rough ground.
see_also: [ClearToRoughLat]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Only the set's first tile is used. It is the plain rough ground that [`ClearToRoughLat`](/keys/cleartoroughlat/) blends into other ground. A rough blend cell turns back into this tile when all four of its edge neighbors are rough.

The random map generator grows rough patches on every biome, so both the temperate and the snow theater need this set for generated maps. On temperate and mutated maps rough competes with [`GreenTile`](/keys/greentile/), and on desert maps with [`SandTile`](/keys/sandtile/). On tundra and taiga maps the only other ground patches are [`Rocks`](/keys/rocks/). [Ground cover](/systems/map-generation/#ground-cover) gives the order of the rolls.

:::danger[Set RoughTile in every theater used for generated maps]
If the role is unresolved, rough patches on generated maps are laid as tile index `-1`, which is not a tile. Blending can replace a patch's edge cells, but its inner cells keep that index. On any map, a rough blend cell whose four edge neighbors are all rough also turns into index `-1`. The engine reads outside the theater's tile list when it uses such a cell.
:::
