---
key: ClearToBlueMoldLat
summary: Tile set holding the sixteen blend pieces laid where blue mold meets other terrain.
see_also: [ClearToRoughLat, BlueMoldTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Blue mold blends by the rule [`ClearToRoughLat`](/keys/cleartoroughlat/) describes, against the plain [`BlueMoldTile`](/keys/bluemoldtile/) tile. It blends last of the seven families, so it works on whatever tile the other six left in the cell.

Blue mold keeps blending when this set is unresolved. A theater that resolves `BlueMoldTile` but not this set lays wrong tiles on its blue mold; the caution on [`ClearToRoughLat`](/keys/cleartoroughlat/) gives which.
