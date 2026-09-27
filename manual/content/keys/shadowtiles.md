---
key: ShadowTiles
summary: Second condition a shadow-casting tile set must satisfy before any of its tiles is marked as a caster.
see_also: [ShadowCaster]
when_omitted:
  kind: value
  value: "0"
  note: No tile of the set is marked as a caster, though the set still takes one of the five caster slots.
---

Any non-zero value lets the tiles of a [`ShadowCaster=yes`](/keys/shadowcaster/) set cast shadows, and `0` stops all of them. The key is read only on a set with `ShadowCaster=yes`.

```ini title="TEMPERAT.INI"
[TileSet0010]      ; example cliff set
SetName=Cliffs
FileName=CLIFF
TilesInSet=40
ShadowCaster=yes
ShadowTiles=40     ; any non-zero value has the same effect
```

Despite its name, the value is not a count and cannot limit shadows to some of the set's tiles. Which tiles cast a shadow, and which shadow each draws, depends only on the tile's position in the set, as [`ShadowCaster`](/keys/shadowcaster/) describes.
