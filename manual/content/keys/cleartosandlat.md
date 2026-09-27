---
key: ClearToSandLat
summary: Tile set holding the sixteen blend pieces laid where sand meets other terrain.
see_also: [ClearToRoughLat, SandTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Sand blends by the rule [`ClearToRoughLat`](/keys/cleartoroughlat/) describes, against the plain [`SandTile`](/keys/sandtile/) tile. When this set is unresolved, sand is not blended and keeps its square edges.

The random map generator also tests for these sixteen tiles when it scatters loose rocks. A cell holding one of them gets one of the five sand rock overlays. Plain clear ground and [`ClearToGreenLat`](/keys/cleartogreenlat/) cells get one of the five clear rock overlays instead. While this set is unresolved, the test matches the theater's first fifteen tiles, so clear ground gets sand rocks.
