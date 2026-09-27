---
key: Ice1Set
summary: First of the three sixty-four-tile ice sets a snow theater provides.
see_also: [Ice2Set, Ice3Set, IceShoreSet]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

This set, [`Ice2Set`](/keys/ice2set/) and [`Ice3Set`](/keys/ice3set/) are three ice sets of the same shape. When the engine matches an ice cell's tile to its neighbors, or when ice cracks, breaks or refreezes, it picks one of the three sets at random, so a frozen stretch does not repeat one pattern. Ice growth and the random map generator lay tiles of this set before that matching runs. [Theater control files](/formats/theater-control/) explains how the set number is resolved.

Resolve all three roles in any theater with [`IsIceGrowthEnabled`](/keys/isicegrowthenabled/) on. The ice passes below do not check them, and a pick of an unresolved set lays a tile counted from `-1`, which is not an ice tile.

Keep the three sets consecutive, in the order `Ice1Set`, `Ice2Set`, `Ice3Set`. Several tests treat a whole range of tiles, from the first tile of this set to a point in a later set, as ice. [`Ice2Set`](/keys/ice2set/) and [`Ice3Set`](/keys/ice3set/) describe where those ranges end.

Every ice set holds 64 tiles in the same fixed layout, and replacement artwork must keep it:

| Offset in the set | Tile |
| --- | --- |
| 0 | Full ice with full ice on all four sides |
| 1 | Full ice that the engine never lays |
| 2 to 15 | Full ice for the other patterns of full-ice neighbors |
| 16 | Cracked ice, also laid for full ice with no full-ice neighbor |
| 17 to 63 | Edge pieces, where ice meets open water |

A full-ice cell's tile depends on which of its four side neighbors hold full ice (offsets 0 to 15 of any ice set). Cracked ice does not count as full ice. With all four neighbors full, the cell gets offset 0. Each of the other fifteen patterns selects one of offsets 2 to 16, and the pattern with no full-ice neighbor selects offset 16. A cracked cell keeps its tile until it refreezes or breaks.

A cell that holds open water or an edge piece gets an edge piece chosen from all eight neighbors. A neighbor counts toward that choice when it holds anything other than open water, an edge piece or a [`ShorePieces`](/keys/shorepieces/) tile. The land-side pieces of [`IceShoreSet`](/keys/iceshoreset/) are chosen through the same table of patterns, with a different test for which neighbors count.

These passes run only in a theater with `IsIceGrowthEnabled` on. They run after the [random map generator](/systems/map-generation/) lays ice, and during play whenever ice cracks, breaks, grows or refreezes.

Cracking and breaking need only the theater setting. A heavy enough vehicle (see [`IceCrackingWeight`](/keys/icecrackingweight/) and [`IceBreakingWeight`](/keys/icebreakingweight/)) or an explosion from a [`Wall`](/keys/wall/#scope-warheadtype) or [`Fire`](/keys/fire/) warhead can crack or break ice in any scenario in such a theater. Growth and the refreezing of cracked ice also need the map's [`IceGrowthEnabled`](/keys/icegrowthenabled/).
