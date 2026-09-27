---
key: Width
scope: random-map-generation
label: Generated map width
see_also: ["Height", "NumPlayers"]
when_omitted:
  kind: value
  value: "0"
  note: The narrowest playable area the chosen player count allows.
---

The figure is a size index, not a cell count. It sets the width of the generated playable area the same way [`Height`](/keys/height/#scope-random-map-generation) sets its depth, from the same size range for the player count. `0` gives the narrowest map for that many players and `3` the widest. Equal `Width` and `Height` give a square playable area. The generated map is four columns wider than the playable area. [Map seed files](/formats/map-seed/) covers the section it is written in.

```ini title="map seed file"
[RandomMap]
NumPlayers=4
Width=3
```

On a map whose [`Biome`](/keys/biome/) is mutated, `Width` and `Height` also set how many mold and crystal growths appear. With N equal to `(Width + 1) × (Height + 1)`, the generator makes between 3 and N / 4 + 4 mold attempts, with N / 4 rounded down, and between 6 and N + 8 crystal attempts. An attempt that finds no room places nothing.

When a map is [generated from a file](/systems/map-generation/#the-dialog-path-and-the-scenario-path), a value below `0` becomes `0` and one above `3` becomes `3`.
