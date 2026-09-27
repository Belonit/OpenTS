---
key: Ice2Set
summary: Second of the three sixty-four-tile ice sets a snow theater provides.
see_also: [Ice1Set, Ice3Set]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

The set has the same layout and treatment as [`Ice1Set`](/keys/ice1set/), which describes the layout the three ice sets share and how the engine picks tiles from them. Ice growth thickens this set's edge pieces as it does those of `Ice1Set`; see [`Ice3Set`](/keys/ice3set/) for the set it skips.

This set's position also ends one range of tiles treated as ice. After the [random map generator](/systems/map-generation/) lays an ice sheet, it scatters patches of cracked ice and edge pieces over it. A patch spreads only into cells whose tile lies between the first tile of `Ice1Set` and the last tile of this set. With the three sets consecutive in order, that range covers the first two sets.

Place this set directly after `Ice1Set`. Anywhere else, patches either stop at their first cell or spread onto cells holding unrelated tiles that fall inside the range.
