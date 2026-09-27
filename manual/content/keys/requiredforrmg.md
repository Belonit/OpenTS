---
key: RequiredForRMG
summary: Tile set whose artwork is kept in memory on a generated map even while no cell uses it.
see_also: [AllowToPlace, TilesInSet]
when_omitted:
  kind: value
  value: "no"
---

On a [generated map](/systems/map-generation/#what-the-theater-must-supply), the artwork of a set with `RequiredForRMG=yes` is loaded when the map is read, even if no cell uses the set yet. On any other map the flag has no effect.

```ini title="TEMPERAT.INI"
[TileSet0042]        ; example set the generator lays down as it works
SetName=Shore pieces
FileName=SHORE
TilesInSet=12
RequiredForRMG=yes
```

After a map is read, the engine loads the artwork of every tile the map uses and discards the rest. A generated map places most of its tiles after that point. A discarded tile's artwork is read back from disk the first time the game needs it, so the flag only moves that read forward to map load. A set without the flag still appears correctly on a generated map.
