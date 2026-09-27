---
key: CrystalCliff
summary: Tile set holding the crystal cliff pieces.
see_also: [CliffSet, CrystalTile, ClearToCrystalLat]
when_omitted:
  kind: value
  value: "-1"
  note: The role stays unresolved, because no tile set number can match it, and crystal ground then counts some cells of the theater's first, fourth and fifth tiles as crystal.
---

Crystal ground counts some cells of four crystal cliff pieces as crystal. Each piece covers several cells, numbered across each row from 0 at the top left. A neighboring cell counts as crystal when it holds any of:

- the set's first piece, on cell `0` or `1`,
- the second piece, on cell `2` or above,
- the fifth piece, on an even-numbered cell,
- the sixth piece, on an odd-numbered cell.

Every other cell of those four pieces, and every cell of the set's other pieces, counts as foreign. A crystal cell next to a foreign neighbor takes a blend edge from [`ClearToCrystalLat`](/keys/cleartocrystallat/). [Theater control files](/formats/theater-control/) explains how a `[General]` role is resolved to a tile.

The random map generator also places pieces of this set, on mutated-biome maps with Firestorm enabled:

- A crystal deposit that starts on a cliff face hangs a crystal formation off it, using the set's first, second, fifth or sixth piece.
- When the cliff pass lays a north-west inside corner or a lone north-west outside corner, it has a one-in-twenty chance of laying a crystal cliff piece instead. Six of the forty [`CliffSet`](/keys/cliffset/) shapes are affected.

:::caution[Distance from the cliff set]
A crystal cliff piece that replaces a cliff piece is placed at an offset read from unrelated data, unless this set's first tile is at most 36 tiles after the first `CliffSet` tile. The offset comes from a forty-entry table of cliff placements, and a larger gap reads past its end. The stock temperate control file puts the two sets more than 900 tiles apart, so every crystal substitution in the stock game is affected.
:::
