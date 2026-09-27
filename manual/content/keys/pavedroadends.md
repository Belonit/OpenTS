---
key: PavedRoadEnds
summary: The tile set that supplies the four caps that close the end of a paved road.
see_also: [PavedRoads, PavedRoadSlopes]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

Only the [random map generator](/systems/map-generation/#settlements) uses this role. It closes a paved road with one of the set's first four tiles, chosen by the direction the road runs out in:

| Offset | Road end |
| --- | --- |
| 0 | East |
| 1 | North |
| 2 | West |
| 3 | South |

The generator lays a cap at the road ends below. At each of them, it may instead choose a longer end piece from [`PavedRoads`](/keys/pavedroads/) at random when there is room for one.

- Both ends of each east-west town road.
- Both ends of each north-south town road. Where the road starts on an east-west road, it joins it with a `PavedRoads` junction piece instead. Where it meets an east-west road within four cells of its end, it ends in a junction piece and gets no south cap.
- Both ends of each low bridge the generator builds. There, the room for a longer end piece must also be level.

A north-south town road that is blocked partway, and cannot cross an east-west road there, stops with a south cap. If the road resumes further south, the new stretch starts with a north cap, or with a junction piece where it starts on an east-west road. Neither end of the gap is offered a longer end piece. A stretch that would resume less than two cells before the road's end is not laid.

A cap does not count as pavement for the [`ClearToPaveLat`](/keys/cleartopavelat/) blend, so pavement next to a cap gets a blended edge.

:::caution[Set PavedRoadEnds in any theater that gets towns or bridges]
The generator does not check that this role is bound. Without it, the game can crash while generating a town or bridge, because an east cap reads a tile that does not exist. The other caps lay unrelated tiles from the start of the theater.
:::
