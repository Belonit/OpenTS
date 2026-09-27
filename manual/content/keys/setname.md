---
key: SetName
summary: Section heading a tile set's per-tile animations are read from, and the stem of the name each of its tiles uses.
see_also: [FileName, TilesInSet]
when_omitted:
  kind: value
  value: No Name
---

`SetName` names the section that attaches animations to the set's tiles. If the control file has a section with exactly that heading, including case, its entries give each tile of the set its animation, numbered from 1 within the set. Only the first 63 characters of the value are matched against section headings. Alternate artwork for a tile gets no animation. [Theater control files](/formats/theater-control/) lists the entries that section accepts.

```ini title="TEMPERAT.INI"
[TileSet0631]         ; example set
SetName=Riverbank cliffs
FileName=RVCLIF
TilesInSet=8

[Riverbank cliffs]    ; matched by name, not by set number
Tile03Anim=MYFALLS    ; example AnimType registered in rules.ini
```

Two sets with the same value read the same section, and each applies the entries to its own tiles by number.

The value also labels the set's tiles, as `Riverbank cliffs 01` and upward in the example above. Those labels have no effect on play.

:::caution[Sets without a SetName share the `[No Name]` section]
Every set that omits the key is matched against `[No Name]`. If the control file has a section with that heading, its entries apply to all of those sets at once.
:::
