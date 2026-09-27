---
key: ClearToPaveLat
summary: Tile set holding the sixteen blend pieces laid where pavement meets other terrain.
see_also: [ClearToRoughLat, PaveTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Pavement blends by the rule [`ClearToRoughLat`](/keys/cleartoroughlat/) describes, and counts more neighbors as its own than any other family. Besides the plain [`PaveTile`](/keys/pavetile/) tile and these sixteen, a neighbor counts as pavement when it holds any of:

- one of the fourteen [`MiscPaveTile`](/keys/miscpavetile/) pieces,
- one of the fourteen [`Medians`](/keys/medians/) pieces,
- one of the first eight tiles of the [`PavedRoads`](/keys/pavedroads/) set.

A median or one of those road pieces beside pavement therefore does not cut a blended edge into it.

When this set is unresolved, pavement is not blended and keeps its square edges.
