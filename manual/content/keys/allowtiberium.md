---
key: AllowTiberium
summary: Lets Tiberium take root on the tiles of a theater tile set.
see_also: ["system:tiberium"]
when_omitted:
  kind: value
  value: "no"
---

`AllowTiberium=yes` lets new Tiberium start on the set's tiles. With `no`, a cell showing one of the set's tiles refuses every new patch, however clear the cell is otherwise. That covers [spread](/systems/tiberium/#spread) from a neighboring cell and every seed listed under [Other sources of Tiberium](/systems/tiberium/#other-sources-of-tiberium). The value applies to every tile the set produces, including its lettered alternates.

Tiberium that the map already places on such a tile stays, and it keeps growing. A cell with no valid tile, which the game draws as clear ground, accepts new Tiberium whatever the clear tile set says.
