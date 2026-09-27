---
key: MiscPaveTile
summary: Fourteen-tile set of pavement patches and weathering used to dress paved ground.
see_also: [PaveTile, ClearToPaveLat]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

The [random map generator](/systems/map-generation/#settlements) uses thirteen of the set's fourteen tiles to dress a town's pavement. Offsets count from the set's first tile as offset 0; offset 7 is never placed.

| Offsets | How the generator uses them |
| --- | --- |
| 0 to 6 | Small patches scattered over the town's plain pavement. Offsets 4 to 6 are placed only on a two-by-two block of plain pavement. |
| 8 to 13 | Large weathering patches. Each patch repeats one tile every two cells across a rectangle of 6 by 4, 4 by 6, 4 by 4, 4 by 2 or 2 by 4 cells. Every cell of the rectangle must be empty and hold pavement or one of offsets 0 to 7. |

All fourteen tiles count as pavement for the [`ClearToPaveLat`](/keys/cleartopavelat/) blend, so a patch does not cut blended edges into the pavement around it. The generator also accepts them as pavement when it places roads and buildings.

:::caution[Set MiscPaveTile in any theater that gets towns]
The generator does not check that this role is bound. Without it, the generator lays unrelated tiles from the start of the theater as patches, and a patch at offset 0 reads a tile that does not exist, which can crash the game. It also takes any of the theater's first thirteen tiles for a pavement patch when choosing where roads and buildings may go.
:::
