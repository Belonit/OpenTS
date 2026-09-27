---
key: Ice3Set
summary: Third of the three sixty-four-tile ice sets a snow theater provides.
see_also: [Ice1Set, Ice2Set, IceShoreSet]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

The set has the same layout as [`Ice1Set`](/keys/ice1set/), which describes the layout the three ice sets share and how the engine picks tiles from them. Cracking, breaking and refreezing treat it like the other two.

Ice growth never thickens this set. Where the map has [`IceGrowthEnabled`](/keys/icegrowthenabled/) on, growth turns edge pieces of `Ice1Set` and [`Ice2Set`](/keys/ice2set/) into full ice in cells whose map data allows ice growth, but an edge piece from this set stays an edge piece. The last edge piece of each set, offset 63, never grows either.

This set's position ends the range of tiles that [`IceShoreSet`](/keys/iceshoreset/) treats as ice. When the shore pieces are chosen, a neighbor counts as ice if its tile lies between the first tile of `Ice1Set` and the last tile of this set. Keep the three sets consecutive in order. A gap or a different order either drops ice out of that range or counts unrelated tiles as ice.
