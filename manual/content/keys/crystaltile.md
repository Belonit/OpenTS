---
key: CrystalTile
summary: Tile set whose first tile is a theater's plain crystal ground.
see_also: [ClearToCrystalLat]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is selected, so the role stays unresolved.
---

Only the set's first tile is used. It is the plain crystal ground that [`ClearToCrystalLat`](/keys/cleartocrystallat/) blends against, and the tile a crystal cell returns to when all four of its edge neighbors are crystal.

The random map generator lays crystal ground only on mutated-biome maps, which use the temperate theater. Each crystal deposit covers a spread of cells with this tile. The generator then plants up to five crystal terrain objects, drawn from `FONA06` to `FONA15`, each on a random cell of the deposit that still holds this tile and is not protected.
