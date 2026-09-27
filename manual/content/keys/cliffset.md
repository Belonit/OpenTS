---
key: CliffSet
summary: Tile set holding the theater's forty cliff faces.
see_also: [CliffRamps, CrystalCliff, WaterCliffs, DestroyableCliffs]
when_omitted:
  kind: value
  value: "-1"
  note: The role stays unresolved, because no tile set number can match it. When the generator then lays a tile over a shore piece, it counts the theater's first thirty-nine tiles as cliff and treats laying one of them there as a failed placement.
---

The random map generator is the only reader of this role. It picks each cliff piece by its position in the set, counted from 1, so a replacement set must keep its forty pieces in the same order as the set it replaces. [Theater control files](/formats/theater-control/) explains how a `[General]` role is resolved to a tile.

The generator counts a tile as cliff when it falls within these forty pieces. On mutated-biome maps, which need Firestorm, it also hangs crystal formations from the pieces at positions 5 to 7 and 15 to 17.

This role does not affect movement; a cliff's land type comes from its artwork.

:::danger[Resolve this role before generating a map]
The cliff pass uses this role as a tile index without checking that it resolved. With the role unresolved, the piece at position `n` becomes the theater's tile at index `n - 2`, so position 1 asks for the tile at index `-1`. If [`CrystalCliff`](/keys/crystalcliff/) resolves while this role does not, the crystal substitution also reads past the end of the placement-offset table described on that page.
:::
