---
key: ExtraLight
summary: The lighting offset applied to the structure's own artwork.
see_also: ["TerrainPalette", "BibShape", "UnderDoorAnim"]
when_omitted:
  kind: value
  value: "0"
---

`ExtraLight` draws a structure brighter or darker than the ground it stands on. The value is added to the lighting level of the structure's cell, on a scale where 1000 is unmodified light. `ExtraLight=-100` draws the structure 100 points darker than its cell; 100 points is a tenth of unmodified light. A positive value brightens it by the same measure.

```ini title="art.ini"
[MYICBM] ; example missile launcher, drawn from its own Image ID
ExtraLight=-100
```

The value has no limit, but its sum with the cell's lighting level does. At a sum of `0` or less the artwork is drawn at its darkest shade, and above about `2000` it is drawn no brighter than at `2000`.

The value applies to the structure's main artwork, its [`BibShape`](/keys/bibshape/) apron, its [`UnderDoorAnim`](/keys/underdooranim/), and the copy of the structure drawn under fog. It does not apply to:

- the [`DoorAnim`](/keys/dooranim/) frames;
- a [`Gate=yes`](/keys/gate/) structure while its gate is open or moving;
- the structure's attached animations and its voxel turret.

A [`TerrainPalette=yes`](/keys/terrainpalette/) structure ignores the value while it is drawn normally, because it takes its lighting from the cell's terrain tile instead. Its copy under fog still uses the value.
