---
key: Rocks
summary: Tile set whose first tile is the rock ground the random map generator paints on snow maps.
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Only the random map generator uses this set, and only its first tile. On tundra and taiga maps it grows patches of rock ground alongside rough ground and woods, as [Ground cover](/systems/map-generation/#ground-cover) describes. Temperate, desert and mutated maps never use it, so it matters only in the snow theater. On desert maps the generator grows [`SandTile`](/keys/sandtile/) patches instead.

The engine has no transition set for rock, so a rock patch gets no blend pieces at its edges.

:::danger[Set Rocks in the snow theater]
If the role is unresolved, every rock patch on a tundra or taiga map is written into its cells as tile index `-1`, which is not a tile. The engine reads outside the theater's tile list when it uses those cells.
:::
