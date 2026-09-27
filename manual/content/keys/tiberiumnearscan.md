---
key: TiberiumNearScan
summary: Distance a harvester searches for the next Tiberium cell once the cell it is working runs out.
see_also: ["system:tiberium", "TiberiumFarScan"]
when_omitted:
  kind: value
  value: "6"
---

A harvester that has emptied its cell, or has just filled up, searches for Tiberium up to one cell less than this distance. The value is in cells and is truncated to a whole number, so the default `6` reaches 5 cells from the harvester.

- A harvester with room left drives to the cell the search finds. If the search finds nothing, it heads home with a partial load.
- A full harvester records the cell the search finds as the patch to drive back to after unloading, then heads home.

A [weeder](/systems/veins/) uses the same limit while it works a field of veins. [Loading](/systems/tiberium/#loading) describes the harvesting cycle around these searches.
