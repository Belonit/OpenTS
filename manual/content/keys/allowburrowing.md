---
key: AllowBurrowing
summary: Ground that a subterranean unit may dive into or surface through.
see_also: [Morphable, AllowTiberium]
when_omitted:
  kind: value
  value: "yes"
---

`AllowBurrowing=no` keeps subterranean units from diving into or coming up through any tile of the set. The value applies to every tile the set produces, including its lettered alternates.

A cell lets a subterranean unit burrow there under **All of:**

- the cell's tile allows burrowing;
- the cell is flat, not a slope;
- no bridge stands over the cell, and none stood over it before being destroyed;
- no structure stands on it;
- no terrain object stands on it.

A unit ordered to move tests the cell it is heading for and, unless it is already underground, the cell it starts from. If a tested cell fails, it plans a route on the surface instead of tunneling.

```ini title="TEMPERAT.INI"
[TileSet0631]        ; example cliff set
SetName=Riverbank cliffs
FileName=RVCLIF
TilesInSet=8
AllowBurrowing=no    ; nothing surfaces out of a cliff face
```

:::caution[Cells the flag does not cover]
Every cell outside the playable area allows burrowing, whatever its tile and whatever stands on it. A cell with no valid tile, which the game draws as clear ground, skips the tile test and follows only the other four conditions.
:::
