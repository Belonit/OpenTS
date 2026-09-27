---
key: TerrainPalette
summary: Draws the structure with the cell's terrain colors instead of its owner's.
see_also: ["ExtraLight", "Remapable"]
when_omitted:
  kind: value
  value: "no"
---

`TerrainPalette=yes` draws the structure with the same tinted terrain palette as the ground beneath its center, instead of its owner's house colors. A [`Remapable=yes`](/keys/remapable/) structure therefore loses its owner's color. The structure also takes the ground's lighting, so [`ExtraLight`](/keys/extralight/) does not brighten it.

Under fog, the structure's fogged image also uses the terrain palette. Its brightness there is worked out as for any other structure, so `ExtraLight` applies again.

Only structures read this flag. Terrain objects such as trees and rocks do not.

```ini title="art.ini"
[MYTREEHOUSE] ; the art section named by the structure's Image
TerrainPalette=yes
```
