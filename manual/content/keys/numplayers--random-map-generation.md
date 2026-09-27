---
key: NumPlayers
scope: random-map-generation
label: Players the map is built for
see_also: [Width, Height, Seed, TiberiumLayout, Tiberium]
when_omitted:
  kind: value
  value: "2"
  note: Two start points, and the first row of the size table that Width and Height pick a size within.
---

`NumPlayers` sets how many start points the generator places, one for each player. It also selects the row of the map size table that [`Width`](/keys/width/#scope-random-map-generation) and [`Height`](/keys/height/#scope-random-map-generation) pick a size within, so the same size settings give a larger map for more players. [Map seed files](/formats/map-seed/) has the table and covers the `[RandomMap]` section.

```ini title="map seed file"
[RandomMap]
NumPlayers=4
Width=2
Height=2
```

Before a map is built, a value below `2` becomes `2` and a value above `8` becomes `8`.

The generator places the start points after the terrain is finished, spread as far apart as the terrain allows. Each start point needs 400 clear cells around it. If any start point falls short, the generator picks a new set of start points on the same terrain and tries again. The number of tries has no limit, so generation never finishes on terrain that cannot fit that many start points. [Start points and the layout spread](/systems/map-generation/#start-points-and-the-layout-spread) covers the placement.

The player count also scales the tiberium. The tiberium fields away from the start points share an amount set by [`Tiberium`](/keys/tiberium/#scope-random-map-generation) and `NumPlayers`, so a map built for more players gets more tiberium in those fields. The number of those fields comes from [`TiberiumLayout`](/keys/tiberiumlayout/) and does not depend on the player count.

Write `NumPlayers` in every seed file you distribute. The skirmish setup and the multiplayer lobby read it as the map's player limit and treat a missing value as `0`, so the map cannot be started. [Start positions a lobby counts](/keys/numplayers/#scope-random-map-generation-2) covers that read.
