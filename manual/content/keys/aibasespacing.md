---
key: AIBaseSpacing
summary: Cells of clearance kept around a building when base ground is reserved and computer placements are searched.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: "1"
---

`AIBaseSpacing` sets the margin the computer keeps around each structure of its base. While the base has room, the computer's [placement search](/systems/ai-base-building/#the-placement-search) leaves a gap of at least twice this many cells between a new structure and the others, so a higher value spreads the base out.

Every structure placed on the map, by any house, reserves its footprint plus this many cells on each side for its owner. A structure that sets [`UndeploysInto`](/keys/undeploysinto/) and is not a construction yard reserves nothing. Only the computer's placement search reads which cells are reserved, and each house's search reads only its own.

The reserved area also extends the owner's base rectangle. A larger margin therefore moves a computer base's [planned perimeter walls](/systems/ai-base-building/#walls-and-gates) further from its structures.

The search uses the margin in two tests:

- The candidate structure's footprint, grown by the margin on every side, must contain no cell the house has reserved. The search tries up to three positions outward from each edge cell of the reserved area. If all three fail, it tries that edge cell again, starting one cell closer to the base and without the margin in this test, before it moves to the next edge cell. A structure can therefore be placed without the margin while a less preferred edge cell still has room. If every edge cell fails, a final pass skips this test.
- For a house not following a map plan, the [compactness test](/systems/ai-base-building/#the-compactness-test) requires a cell the house has reserved within the grown footprint or a ring around it. The ring is one cell wide on the north and west and `AIBaseSpacing` plus one cells wide on the south and east. This test always uses the full margin.
