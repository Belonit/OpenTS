---
key: FileName
summary: Stem of the artwork file names a tile set loads its tiles from.
see_also: [TilesInSet, SetName, NonMarbleMadness]
when_omitted:
  kind: value
  value: TILE
---

Each tile of the set loads the file named by this stem, the tile number and the theater's file extension. The tile number counts from `01` and has at least two digits. [Theater control files](/formats/theater-control/) covers the lettered alternates built on the same stem and the second extension tried when a file is missing.

```ini title="TEMPERAT.INI"
[TileSet0631]      ; example set
SetName=Riverbank cliffs
FileName=RVCLIF    ; loads RVCLIF01.TEM through RVCLIF08.TEM
TilesInSet=8
```

Check that every file the stem produces exists. A missing file does not stop the theater from loading or shift the numbering of the tiles after it: the tile still takes its place in the set, with zero width and height and no artwork.

The stem is read to at most 63 characters; anything longer is cut off.
