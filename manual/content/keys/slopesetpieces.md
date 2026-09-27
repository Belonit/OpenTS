---
key: SlopeSetPieces
summary: Tile set holding the ten slope pieces that carry ground between height levels.
see_also: [SlopeSetPieces2, RampBase, DestroyableCliffs]
when_omitted:
  kind: value
  value: "-1"
  note: The role stays unresolved, because no tile set number can match it. The ramp substitutions then apply to the theater's fifth and eighth tiles, and the theater's fourth and sixth tiles draw slope shadows if their set casts shadows.
---

The set holds ten multi-cell slope pieces, larger than the single-cell ramps of [`RampBase`](/keys/rampbase/). The engine picks each piece by its position in the set, so a replacement set must keep the same order. [Theater control files](/formats/theater-control/) explains how a `[General]` role is resolved to a tile index.

The random map generator lays all ten pieces when it builds ramps between regions at different heights.

A collapsing cliff is replaced by two of these pieces, which opens a way up the rock. The first [`DestroyableCliffs`](/keys/destroyablecliffs/) tile is replaced by the first and second pieces, and the second tile by the fourth and third.

When a structure's `ToTile=` names the sixth or ninth piece, some of the cells it lays become plain ramps:

- The sixth piece becomes the second `RampBase` tile on sub-tiles `0`, `3`, `6` and `9`.
- The ninth piece becomes the first `RampBase` tile on sub-tiles `0` through `3`.

The random map generator writes its pieces straight into the cells, so it keeps them unchanged.

The ten pieces cast shadows only when their set is a shadow caster, as [`ShadowCaster`](/keys/shadowcaster/) describes. They then draw from a fixed slope table in place of the cliff table on that page. Only two pieces have a shadow in the slope table: the fifth, on sub-tile `6`, and the seventh, on sub-tile `1`.

:::danger[Resolve this role wherever DestroyableCliffs is resolved]
The collapse takes its two replacement pieces from the tile list at this role and the three places after it, with no check that the role resolved. In a theater that resolves `DestroyableCliffs` but not this role, collapsing the first cliff tile reads one entry before the start of the tile list. Collapsing the second lays the theater's second and third tiles across the gap as slopes.
:::
