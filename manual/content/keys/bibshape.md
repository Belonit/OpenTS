---
key: BibShape
summary: The apron shape drawn on the ground under a structure.
see_also: ["Bib", "ExtraLight", "Foundation"]
when_omitted:
  kind: value
  value: ""
  note: No apron shape is loaded and none is drawn.
---

`BibShape` names the apron artwork drawn on the ground under a structure: a shape file, written without its extension. `<value>.SHP` is loaded with the rules, with its name adjusted for the theater as [`DoorAnim`](/keys/dooranim/) describes. It is loaded again after a saved game is loaded and, for a [`NewTheater=yes`](/keys/newtheater/) structure, when a scenario's theater is set up.

```ini title="art.ini"
[MYWEAP] ; example war factory, drawn from its own Image ID
BibShape=GAWEAPBB ; loaded as GTWEAPBB.SHP in temperate
```

Every structure of the type draws the apron, with these exceptions:

- no apron is drawn while the structure's buildup plays, including in reverse when it is sold or undeployed;
- a [`Gate=yes`](/keys/gate/) structure draws none while it is opening, open or closing;
- an [`InvisibleInGame=yes`](/keys/invisibleingame/) structure draws none.

The apron is drawn after the structure's own shape and appears on the fogged image of the structure as well. It is lit like the structure: the cell's light level plus the structure's [`ExtraLight`](/keys/extralight/).

## Frames

The apron shows the frame with the same number as the structure's current frame. An apron that should change with the structure's animation or damage needs the same frame layout as the structure's own artwork. When the structure's frame number is beyond the last frame in the apron file, no apron is drawn; the engine does not fall back to frame 0.

## What the apron does not do

The apron is only artwork. It does not add cells to the footprint and does not let vehicles onto it. [`Bib=yes`](/keys/bib/) in the rules file opens the eastern edge of the footprint to vehicles; it ignores this artwork and draws no apron of its own.
