---
key: TiberiumLayout
summary: How many tiberium fields a generated map is given, as a figure from 0 to 100.
see_also: [Tiberium, TiberiumWildlife, UseBlueTiberium, NumPlayers]
when_omitted:
  kind: value
  value: "0"
  note: Three fields spread across the map, on top of the field each player start point gets.
---

A higher `TiberiumLayout` spreads more tiberium fields across a generated map. The map gets three fields plus one for every ten points: `0` gives three fields, `50` gives eight and `100` gives thirteen. Values between the tens round down, so `55` gives the same map as `50`. [Map seed files](/formats/map-seed/) covers the section the key is written in.

```ini title="map seed file"
[RandomMap]
TiberiumLayout=50
Tiberium=60
```

The field count does not depend on the player count. A two-player map and an eight-player map with the same `TiberiumLayout` get the same number of fields.

The field sites are picked in the same step as the start points, from one set of widely spaced cells, so they are spread away from the start points and from one another. [Random map generation](/systems/map-generation/#start-points-and-the-layout-spread) describes that step.

The fields divide one total amount of tiberium, set by [`Tiberium`](/keys/tiberium/#scope-random-map-generation) and [`NumPlayers`](/keys/numplayers/#scope-random-map-generation), so more fields means smaller fields.

Each player also gets a field at their start point. The farther a player's start point is, on average, from the fields above, the larger that start field is.

A value below `0` is used as `0`, and one above `100` as `100`.
