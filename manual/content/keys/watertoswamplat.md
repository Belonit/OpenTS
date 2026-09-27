---
key: WaterToSwampLat
summary: Tile set holding the sixteen blend pieces laid where swamp meets other terrain.
see_also: [ClearToRoughLat, SwampTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Swamp blends by the rule [`ClearToRoughLat`](/keys/cleartoroughlat/) describes, except that more neighbors count as swamp. Besides the sixteen tiles here, a neighbor counts when it holds any of the ten tiles that start at the plain [`SwampTile`](/keys/swamptile/) tile. The `SwampTile` set's nine tiles are the first nine, and the tenth is whatever tile the theater loads next. The eight decorative swamp tiles fall inside that run, so no blend edge forms against them.

When [`SwampTile`](/keys/swamptile/) is resolved, the random map generator counts these sixteen tiles as swamp. When it divides the map into [regions](/systems/map-generation/#regions-cliffs-and-ramps), it therefore groups them with the swamp and water beside them at the same height.

Resolve this set whenever `SwampTile` is resolved. With this set unresolved, swamp still blends, but a blended cell gets one of the theater's first fifteen tiles; [`ClearToRoughLat`](/keys/cleartoroughlat/) says which. The random map generator also counts those fifteen tiles as swamp, and groups cells holding them with water when it divides the map into regions.
