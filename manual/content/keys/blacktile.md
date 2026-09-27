---
key: BlackTile
summary: Tile-set number whose first tile the engine looks up and never uses.
no_effect: true
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

The engine looks up the named set's first tile, as it does for every other role in the [theater control file](/formats/theater-control/), and never uses it.
