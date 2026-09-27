---
key: NonMarbleMadness
summary: Tile-set number whose only live consequence is whether the alternate artwork extension is tried when a tile file is missing.
see_also: [MarbleMadness, FileName]
when_omitted:
  kind: value
  value: "65535"
  note: A non-zero value, which leaves the fallback on.
---

`NonMarbleMadness=0` stops the set's tiles from falling back to the marble madness artwork. Any other value, including the default, leaves the fallback on. Only whether the value is zero matters.

When a tile's file with the theater's extension is missing, the loader tries the same name with the theater's [`MMSuffix`](/keys/mmsuffix/), if the theater has one (`.MMT` in temperate and `.MMS` in snow). The tile uses that artwork if the file exists. With `NonMarbleMadness=0`, the second attempt is skipped and the tile has no artwork.

```ini title="TEMPERAT.INI"
[TileSet0631]         ; example set that has no alternate artwork
SetName=Riverbank cliffs
FileName=RVCLIF
TilesInSet=8
NonMarbleMadness=0    ; do not look for RVCLIF01.MMT and its fellows
```

The value is also read as a tile-set number, like [`MarbleMadness`](/keys/marblemadness/), and matched to a tile in the named set. Nothing uses that match.
