---
key: IceShoreSet
summary: Forty-eight-tile set of the land-side pieces laid where ice meets ground.
see_also: [Ice1Set, Ice3Set]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Only the [random map generator](/systems/map-generation/) lays these pieces, once it has placed ice on a map in a theater with [`IsIceGrowthEnabled`](/keys/isicegrowthenabled/) on. Ice that cracks, breaks, grows or refreezes during play leaves the shore pieces as they are.

The generator dresses a cell that has no tile, holds the theater's first tile (clear ground), or already holds one of these 48 pieces. It notes which of the cell's eight neighbors hold ice, meaning any tile from the first tile of [`Ice1Set`](/keys/ice1set/) to the last tile of [`Ice3Set`](/keys/ice3set/). That pattern leads to one of three results, through the same table that chooses the ice edge pieces:

- a piece from this set, at an offset from 1 to 46; offsets 0, 15 and 47 are never laid;
- full ice, after which the ice and the shore around the cell are dressed again;
- no change to the cell.

:::caution[Resolve this role in a theater with ice]
The shore pass runs whether or not the role resolved. Unresolved, the set is counted from `-1`. The pass then treats the theater's first 47 tiles as shore pieces it may replace, and lays each piece one tile before the offset it means. On a random map, ground next to ice gets unrelated tiles.
:::
