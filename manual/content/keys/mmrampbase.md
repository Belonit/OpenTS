---
key: MMRampBase
summary: Tile set holding the marble madness counterparts of the plain ramps.
see_also: [RampBase, SlopeSetPieces2, RampSmooth]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

This role supplies replacement ramps for two pieces of [`SlopeSetPieces2`](/keys/slopesetpieces2/). It mirrors the substitution [`RampBase`](/keys/rampbase/) makes for [`SlopeSetPieces`](/keys/slopesetpieces/). When one of these pieces is laid onto the map as a tile object, some of its cells take a tile from this set instead:

- Cells under subtiles `0`, `3`, `6` and `9` of the sixth piece take this set's second tile.
- Cells under subtiles `0` to `3` of the ninth piece take this set's first tile.

Nothing else reads the role. The random map generator writes its tiles directly and never makes this substitution, and a collapsing cliff uses `SlopeSetPieces`. In play, the substitution happens only when a structure's `ToTile=` names one of the two pieces. [Theater control files](/formats/theater-control/) explains how a `[General]` role is bound to a tile set, and covers the marble madness artwork the second slope set draws on.

:::caution[Bind MMRampBase if a structure lays those slope pieces]
The substitution does not check that this role is bound. Without it, the ninth piece writes tile index `-1` into the cells under its subtiles `0` to `3`, and later lookups of those cells can crash the game. The sixth piece turns the cells under its subtiles `0`, `3`, `6` and `9` into the theater's first tile.
:::
