---
key: Morphable
summary: Ground that the terrain-reshaping tools are allowed to move, and that will take a smudge.
see_also: [AllowTiberium, AllowBurrowing, Height, Width]
when_omitted:
  kind: value
  value: "no"
---

`Morphable=yes` lets the ground under a tile set change height, take smudges, and be repaved by a structure. The value applies to every tile in the set. A cell whose tile comes from a set with `Morphable=no` is protected in three ways:

- Craters from a warhead's [`Deform`](/keys/deform/) and from meteors under [`CraterLevel`](/keys/craterlevel/) leave the cell's corners where they are, and so do the [random map generator's hills](/systems/map-generation/#hills). This holds even when nothing stands on the cell, although objects on a cell can also prevent a height change. A destroyable cliff that collapses still changes the height of the cells under it and under the slope that replaces it, whatever their setting.
- No crater, scorch mark or other smudge created during play is placed on it. A smudge the map itself lists is placed regardless. [`Height`](/keys/height/#scope-smudgetype) explains the rest of the smudge placement test, including how a smudge covering several cells is checked.
- A structure with `ToTile=` in its rules.ini section, which repaves its footprint with a tile of its own, cannot be built on it.

A cell with no valid tile counts as morphable for height changes and for `ToTile=` structures. The smudge test uses the setting of the theater's first tile for such a cell instead.

```ini title="TEMPERAT.INI"
[TileSet0631]      ; example cliff set
SetName=Riverbank cliffs
FileName=RVCLIF
TilesInSet=8
Morphable=no       ; cliffs stay where the artwork puts them
```

The setting has no other effect. It does not change movement, general buildability, Tiberium growth, or terrain blending.
