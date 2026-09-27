---
key: Size
scope: scenarios
label: Playfield rectangle
see_also: ["system:map-visibility", LocalSize]
when_omitted:
  kind: value
  value: "1,1,50,50"
---

The width and height set the playfield, which is every cell the map has. Nothing can stand, move or be revealed outside it. The first two numbers are ignored, and the playfield always starts at `0,0`.

Loading a map rebuilds every cell, whether or not `Size` is set, so no cell keeps anything from a previously loaded map. Every cell starts [shrouded and fogged](/systems/map-visibility/#cell-state).

```ini title="map file"
[Map]
Size=0,0,120,120
LocalSize=2,2,116,112
```

This [`LocalSize`](/keys/localsize/) is the largest playable area a 120 by 120 playfield allows.
