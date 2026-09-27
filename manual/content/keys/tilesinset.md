---
key: TilesInSet
summary: Count of tiles a tile set contributes to the theater, and the marker that ends the theater read.
see_also: [LastTilesInSet, FileName, SetName]
when_omitted:
  kind: value
  value: "-1"
  note: The theater read stops at this section, and no tile set numbered at or above it is loaded.
---

The count is how many tiles the set adds to the theater. The tiles are numbered on from the last tile of the previous set, and a tile's lettered alternates share its number. [Theater control files](/formats/theater-control/) covers how each tile's artwork file is named from [`FileName`](/keys/filename/).

```ini title="TEMPERAT.INI"
[TileSet0631]      ; example set
SetName=Riverbank cliffs
FileName=RVCLIF
TilesInSet=8       ; RVCLIF01 through RVCLIF08
```

A `[General]` role such as `ShorePieces=` names a tile set by its section number, and the engine resolves it to the number of that set's first tile. A set with a count of `0` still uses up its section number but adds no tiles. A role naming it therefore resolves to the tile number where the next set starts.

The count is not checked against the artwork on disk. A count larger than the files present still creates that many tile types, and the extra ones have no artwork and a width and height of zero.

Any negative count has the same effect as omitting the key.
