---
key: MarbleMadness
summary: Tile-set number that is read but has no effect.
no_effect: true
see_also: [NonMarbleMadness, TilesInSet]
when_omitted:
  kind: value
  value: "65535"
  note: The tiles have no substitute set.
---

`MarbleMadness` names another tile set by its number, the `NNNN` of its `[TileSetNNNN]` section. Each tile of this set is matched to the tile in the same position of the named set, and nothing uses the match. The value changes no drawing, no tile substitution and no multiplayer synchronization check.

[`NonMarbleMadness`](/keys/nonmarblemadness/) is not the mirror of this key that its name suggests: it does have an effect.
