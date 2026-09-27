---
key: CliffRamps
summary: Tile set that starts the twenty tiles the random map generator counts as cliff alongside CliffSet.
see_also: [CliffSet, WaterCliffs, RampBase, SlopeSetPieces]
when_omitted:
  kind: value
  value: "-1"
  note: The role stays unresolved, because no tile set number can match it. When the generator then lays a tile over a shore piece, it counts the theater's first nineteen tiles as cliff and treats laying one of them there as a failed placement.
---

The random map generator counts the twenty tiles that start at this set's first tile as cliff, the same as pieces from [`CliffSet`](/keys/cliffset/). For example, it does not count one of them as high ground when it decides which cells to raise, it does not lay a shore piece over one, and it tries to keep paved roads and settlements away from them. Nothing else reads this role. [Theater control files](/formats/theater-control/) explains how a `[General]` role is resolved to a tile.

The stock temperate and snow theaters set this role to the same set as [`SlopeSetPieces`](/keys/slopesetpieces/). The twenty tiles are then that set's ten slope pieces and the ten of [`SlopeSetPieces2`](/keys/slopesetpieces2/), so the generator treats those slopes as cliff. Whether a tile can be crossed comes from the land type in its artwork, so this role affects only random map generation.
