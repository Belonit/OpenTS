---
key: ShadowCaster
summary: Tile set whose tiles darken the cells below them with a cliff shadow.
see_also: [ShadowTiles, TilesInSet]
when_omitted:
  kind: value
  value: "no"
---

A set with `ShadowCaster=yes` casts cliff shadows only if [`ShadowTiles`](/keys/shadowtiles/) is also non-zero. With `ShadowTiles` at `0`, no tile of the set casts anything, but the set still counts toward the theater's limit of five shadow-casting sets.

The shadows come from a fixed engine table, not from the set's artwork. A tile's position in the set, counted from 0, selects its entry. Only positions 20 through 32 have a shadow, so the 21st through 33rd tiles are the ones that cast. Each draws one frame of the shared `C_SHADOW.SHP` shape, and only on the cell that shows the sub-tile its entry names. Sub-tiles number a tile's cells row by row, starting from 0 at the top left.

| Position | `C_SHADOW.SHP` frame | Sub-tile |
| --- | --- | --- |
| 20 | 1st | 0 |
| 21 | 1st | 0 |
| 22 | 2nd | 1 |
| 23 | 3rd | 1 |
| 24 | 4th | 1 |
| 25 | 5th | 0 |
| 26 | 6th | 0 |
| 27 | 7th | 1 |
| 28 | 8th | 0 |
| 29 | 9th | 0 |
| 30 | 10th | 1 |
| 31 | 11th | 1 |
| 32 | 12th | 0 |

A tile at positions 20 through 32 also shades a fixed group of nearby cells. Infantry and vehicles standing on the ground in those cells are drawn darker.

A flagged set's tiles that are also among the first ten pieces of [`SlopeSetPieces`](/keys/slopesetpieces/) or [`SlopeSetPieces2`](/keys/slopesetpieces2/) take their shadow from a separate slope table instead.

```ini title="TEMPERAT.INI"
[TileSet0010]        ; example cliff set
SetName=Cliffs
FileName=CLIFF
TilesInSet=40
ShadowCaster=yes
ShadowTiles=40
```

:::danger[Flag at most five tile sets in a theater]
The engine has room for five shadow-casting sets. A sixth set with `ShadowCaster=yes` casts no shadow of its own, and registering it overwrites engine memory past the end of that five-set table. Every set with the flag counts, including one whose `ShadowTiles` is `0`.
:::

:::caution[Keep shadow-casting sets at least forty tiles apart]
A tile takes its shadow from the first shadow-casting set, in set-number order, that starts no more than 39 tiles before it. If a later caster set starts within forty tiles of an earlier one, their positions are counted from the earlier set's first tile, so they get the wrong shadows.
:::
