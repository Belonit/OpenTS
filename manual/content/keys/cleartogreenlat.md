---
key: ClearToGreenLat
summary: Tile set holding the sixteen blend pieces laid where green terrain meets other terrain.
see_also: [ClearToRoughLat, GreenTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Green ground blends by the rule [`ClearToRoughLat`](/keys/cleartoroughlat/) describes, against the plain [`GreenTile`](/keys/greentile/) tile. When this set is unresolved, green ground is not blended and keeps its square edges.

When the random map generator scatters loose rocks, it treats these sixteen tiles like clear ground; [`ClearToSandLat`](/keys/cleartosandlat/) gives the rule.
