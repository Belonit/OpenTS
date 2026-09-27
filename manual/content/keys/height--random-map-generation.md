---
key: Height
scope: random-map-generation
label: Generated map height
see_also: ["Width"]
when_omitted:
  kind: value
  value: "0"
  note: The smallest playable area the chosen player count allows.
---

The value is a size index from `0` to `3`, not a cell count. It sets the depth of the generated playable area between a smallest and a largest size that depend on the player count. `0` gives the smallest size and `3` the largest. `1` and `2` give a third and two thirds of the way between them, rounded down to whole cells. At two players the range is 50 to 100 cells, and at eight players it is 135 to 175. [Map seed files](/formats/map-seed/) gives the range for every player count and describes the section the key is written in.

```ini title="map seed file"
[RandomMap]
NumPlayers=4
Height=3
```

The playfield is twelve cells deeper than the playable area.

On a mutated map, `Height` also raises the upper limit on how many mold and crystal growths the map gets. [`Width`](/keys/width/#scope-random-map-generation) gives the formula.

Before a map is built from [either the dialog or a scenario file](/systems/map-generation/#the-dialog-path-and-the-scenario-path), a value below `0` becomes `0` and one above `3` becomes `3`.
