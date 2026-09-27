---
key: WaterfallEast
summary: The tile set that supplies the four pieces of a waterfall running east.
see_also: [WaterfallWest, WaterfallNorth, WaterfallSouth, WaterSet]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The role names the tile set whose four tiles make an east-running waterfall. The [random map generator](/systems/map-generation/#water) lays the first and last tile at the two ends of the fall and fills the stretch between them with the second and third.

Every tile in the set counts as holding water. Outside random map generation this matters in one place: a transport vehicle standing on a waterfall tile refuses to take on a passenger, as it does on open water or a shore piece.

Random map generation also treats the set as rock face, except where the fall spills out onto ordinary ground. For this set those are subtiles `0` and `4` of the first and last tile. The cliff test checks the four roles in the order east, west, south, north and stops at the first set that holds the tile. If two roles name the same tile set, the spared subtiles of the earlier role apply.

The falling water animates from the `Tile<NN>Anim` entries in the section named by the set's [`SetName`](/keys/setname/) in [the theater control file](/formats/theater-control/). Any tile set can carry those entries, so a waterfall animates whether or not a role names its set.

:::caution[Resolve all four waterfall roles]
An unresolved role still takes part in the water test. The water test then counts the theater's first three tiles as water, so a transport standing on one of them refuses its passengers. When random map generation checks whether a tile may be laid over a shore piece, it treats those three tiles as rock face as well. On a random map that places a waterfall running in the unresolved role's direction, the generator looks up the role's first tile outside the tile list.
:::

:::tip[A theater without waterfall art]
Random maps use only the temperate and snow theaters. In any other theater, point the roles at the [`WaterSet`](/keys/waterset/) set. That resolves them without adding any tile to the water test, because that set's first four tiles already count as water. Do not do this in a theater that random maps use. Random map generation would then treat those four tiles as rock face, apart from the spared subtiles, and most of the open water it lays uses them.
:::
