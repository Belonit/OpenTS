---
key: LastTilesInSet
summary: Number of tiles the set held when the maps in circulation were numbered, so that older tile indices can be shifted into line.
see_also: [TilesInSet]
when_omitted:
  kind: value
  value: "-1"
  note: No shift is recorded for this set, so it moves no tile index.
---

`LastTilesInSet` keeps older maps drawing the right terrain after a tile set grows. A map stores each cell's terrain as a tile index counted across every set in the theater, so adding tiles to one set moves the tiles of every later set up. Give this key the count the set had when the older maps were made; [`TilesInSet`](/keys/tilesinset/) gives the count it has now.

```ini title="TEMPERAT.INI"
[TileSet0042]      ; example set that gained four tiles after release
SetName=Shore pieces
FileName=SHORE
TilesInSet=12      ; twelve tiles are loaded
LastTilesInSet=8   ; maps were numbered when there were eight
```

When a map is read, every tile index that points past the set's old end moves up by the difference between the two counts, four in this example. Indices in this set and in earlier sets are unchanged. The set's new tiles must therefore be added at its end.

`LastTilesInSet=0` marks a set added after the maps were made. Every older index from that set's position onward moves up by the set's full count.

Shifts from several sets add up. Each set's position is measured in the old numbering, so every set that changed size must declare its old count for later sets to line up. A value equal to `TilesInSet` records no shift.

:::caution[Declare the old count for every set that changed size]
If a set grew and this key is left out, nothing shifts, and older maps show the wrong tile wherever they use a later set. A value larger than `TilesInSet` moves later indices down by the difference, which is right only when the set actually lost tiles from its end.

Every map the game reads is shifted, including one made after the set grew. A map numbered against the current counts then shows the wrong tiles, so keep all maps on the old numbering while this key is set.
:::
