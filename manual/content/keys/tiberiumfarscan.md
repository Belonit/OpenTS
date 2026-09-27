---
key: TiberiumFarScan
summary: Distance a harvester searches for Tiberium when it sets out with no recorded patch to return to.
see_also: ["system:tiberium", "TiberiumNearScan"]
when_omitted:
  kind: value
  value: "32"
---

A harvester that is not full and has no recorded patch to drive back to searches for Tiberium up to one cell less than this distance. The value is in cells and is truncated to a whole number, so the default `32` reaches 31 cells from the harvester and `32.9` reaches no further. A [weeder](/systems/veins/) uses the same limit when it sets out to look for veins.

If the search finds nothing and the harvester has nowhere to drive, it gives up and goes to guard. A Tiberium harvester that gives up also marks its house short of Tiberium. [Finding a patch](/systems/tiberium/#finding-a-patch) describes the search, the cells it skips, and what being short of Tiberium does to a computer-controlled house.
