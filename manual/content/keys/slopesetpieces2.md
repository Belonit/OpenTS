---
key: SlopeSetPieces2
summary: Tile set holding the marble madness counterparts of the slope pieces.
see_also: [SlopeSetPieces, MMRampBase]
when_omitted:
  kind: value
  value: "-1"
  note: The role stays unresolved, because no tile set number can match it. The ramp substitutions then apply to the theater's fifth and eighth tiles. The theater's fourth and sixth tiles draw slope shadows if their set casts shadows.
---

The set holds the marble madness versions of the ten [`SlopeSetPieces`](/keys/slopesetpieces/) pieces, in the same order. [Theater control files](/formats/theater-control/) explains how a `[General]` role is resolved to a tile index and covers the marble madness artwork.

When a structure's `ToTile=` names the sixth or ninth piece, some of the cells it lays become plain marble madness ramps:

- The sixth piece becomes the second [`MMRampBase`](/keys/mmrampbase/) tile on sub-tiles `0`, `3`, `6` and `9`.
- The ninth piece becomes the first `MMRampBase` tile on sub-tiles `0` through `3`.

The ten pieces cast shadows only when their set is a shadow caster, as [`ShadowCaster`](/keys/shadowcaster/) describes. They then use the same slope table as the ordinary slope pieces, in which only the fifth piece, on sub-tile `6`, and the seventh, on sub-tile `1`, have a shadow.

A collapsing cliff never uses this set. It always takes its pieces from `SlopeSetPieces`.
