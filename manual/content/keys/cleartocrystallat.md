---
key: ClearToCrystalLat
summary: Tile set holding the sixteen blend pieces laid where crystal terrain meets other terrain.
see_also: [ClearToRoughLat, CrystalTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Crystal ground blends by the rule [`ClearToRoughLat`](/keys/cleartoroughlat/) describes, against the plain [`CrystalTile`](/keys/crystaltile/) tile.

Crystal is the only family that also counts some cliff cells as its own. A crystal cell next to a counted cell of a [`CrystalCliff`](/keys/crystalcliff/) piece gets no blend edge on that side. The `CrystalCliff` page lists which pieces and cells count.

Crystal keeps blending when this set is unresolved. A theater that resolves `CrystalTile` but not this set lays wrong tiles on its crystal ground; the caution on [`ClearToRoughLat`](/keys/cleartoroughlat/) gives which.
