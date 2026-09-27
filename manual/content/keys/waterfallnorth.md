---
key: WaterfallNorth
summary: The tile set that supplies the four pieces of a waterfall running north.
see_also: [WaterfallEast, WaterfallWest, WaterfallSouth]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The role names the tile set whose four tiles make a north-running waterfall. The [random map generator](/systems/map-generation/#water) lays the first and last tile at the two ends of the fall and fills the stretch between them with the second and third.

Every tile in the set counts as holding water, so a transport vehicle standing on one refuses to take on a passenger. Random map generation also treats the set as rock face, except where the fall spills out onto ordinary ground. For this set those are subtiles `2` and `3` of the first and last tile.

[`WaterfallEast`](/keys/waterfalleast/) covers what the four roles share: the order the cliff test checks them in, what an unresolved role does, and where the falling water's animation comes from.
