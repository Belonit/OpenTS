---
key: RoughGround
summary: Ten-tile set of rough ground decorations scattered by the random map generator.
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Only the random map generator uses this set. On desert, mutated, tundra and taiga maps it scatters a few pieces from it across the map, picking each piece from the ten with equal chance. [Ground cover](/systems/map-generation/#ground-cover) gives the count. Desert and mutated maps use the temperate theater and tundra and taiga maps use the snow theater, so both theaters need the set.

These pieces are unrelated to [`RoughTile`](/keys/roughtile/), the plain rough ground that rough patches are made of.

A piece replaces the tile of each cell it covers, and it can cover several cells. It is placed only where each cell it covers is clear ground or a ramp sloped the same way as that part of the piece. Overlays such as tiberium, and objects standing on the cells, do not block it. Any part of a piece that falls off the map is left out.

:::danger[Set RoughGround in every theater used for generated maps]
If the role is unresolved, the generator scatters the theater's first nine tiles in place of the decorations. One pick in ten is index `-1`, which is not a tile, and testing that pick reads outside the theater's tile list.
:::
