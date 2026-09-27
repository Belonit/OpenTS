---
key: PavedRoads
summary: The tile set the fifteen paved road tiles are counted from.
see_also: [PavedRoadEnds, PavedRoadSlopes, ClearToPaveLat, PaveTile]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The first eight tiles of this set count as pavement for the [`ClearToPaveLat`](/keys/cleartopavelat/) blend, alongside the [`MiscPaveTile`](/keys/miscpavetile/) and [`Medians`](/keys/medians/) tiles. Pavement laid against one of these road tiles therefore joins it cleanly, without a blended edge. If the role is not bound to a tile set, road tiles do not count as pavement, and pavement next to a road gets a blended edge.

The [random map generator](/systems/map-generation/#settlements) builds its town roads from this set's tiles, and uses its longer end pieces as an alternative to a [`PavedRoadEnds`](/keys/pavedroadends/) cap at town road ends and at low-bridge ends. It lays new road only over clear ground, pavement and pavement patches. A road or cap it has already laid blocks new road, except where a north-south road crosses an east-west one.

:::caution[Set PavedRoads in any theater that gets towns or bridges]
The generator does not check that this role is bound. Without it, the game can crash while generating a town, because the straight east-west road piece reads a tile that does not exist. Other road pieces lay unrelated tiles from the start of the theater.
:::
