---
key: WaterCliffs
summary: Tile set holding the cliff faces that drop straight into water.
see_also: [CliffSet, CliffRamps, DestroyableCliffs]
when_omitted:
  kind: value
  value: "-1"
  note: The role stays unresolved, because no tile set number can match it, and no tile is recognized as a water cliff.
---

The set holds twenty-eight pieces. The [random map generator](/formats/map-seed/) treats them as cliff, the same as [`CliffSet`](/keys/cliffset/) pieces, and nothing else reads the role. [Theater control files](/formats/theater-control/) explains how a `[General]` role is resolved to a tile index.

Several generator passes avoid or build around cliff cells, water cliffs included: raising high ground, seeding hills, laying shore pieces, and placing bridges and urban areas. For example, a higher neighbor holding a water cliff does not count when the generator decides whether to raise a cell, and a shore piece is refused on a cell holding a water cliff.

On any map, movement reads the land type from the tile artwork, so this role does not change where units can go.
