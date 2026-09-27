---
key: Tiberium
scope: random-map-generation
label: Tiberium richness
see_also: [TiberiumLayout, TiberiumWildlife, UseBlueTiberium, NumPlayers, "system:tiberium"]
when_omitted:
  kind: value
  value: "0"
  note: The generator raises it to 1, so the layout fields still share 2,530 growth steps per player.
---

`Tiberium` sets how much Tiberium a generated map's layout fields hold. [`TiberiumLayout`](/keys/tiberiumlayout/) sets how many fields there are. [Map seed files](/formats/map-seed/) covers the section the key is written in.

```ini title="map seed file"
[RandomMap]
Tiberium=60
TiberiumLayout=40
NumPlayers=4
```

Before building the map, the generator raises a figure below `1` to `1` and lowers one above `100` to `100`. This applies to a seed file and the map generator dialog alike.

The layout fields share `NumPlayers × (30 × Tiberium + 2500)` growth steps, divided evenly between them. In the example above they share 4 × (30 × 60 + 2500) = 17,200 steps. A growth step either plants Tiberium in an empty cell or thickens Tiberium already there by one growth stage. Each field's share then varies at random by up to 100 steps either way, and a field whose share falls below zero is skipped.

Each player's start point also gets a field. Its size does not depend on this setting. The player whose start lies closest to the layout fields, on average, gets 500 steps. Every other player gets 15 more steps for each cell their start lies farther away, on average.

A field grows outward from its first cell one step at a time, filling the nearest cells first with some randomness. The field stays compact with an irregular edge. If it runs out of room before its share is placed, it starts again from the same cell. A field still short after nine starts gets one more growth step and then stops.
