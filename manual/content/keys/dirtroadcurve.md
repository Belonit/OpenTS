---
key: DirtRoadCurve
summary: The tile set the whole run of 101 flat dirt road pieces is counted from.
see_also: [DirtRoadJunction, DirtRoadStraight, DirtRoadSlopes]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The [random map generator](/systems/map-generation/) finds every flat dirt road piece by counting from this role's first tile. It holds a fixed table that records, for each of 101 pieces, where the piece's roads leave it and in which directions. Entry `n` of that table describes the tile `n` places after this role's first tile, both when the generator picks a piece to lay and when it extends the road from a piece it has just laid.

The table expects the 101 tiles from this role to hold these pieces, in this order, with the same shapes as the original theater's:

| Offset from the first tile | Pieces |
| --- | --- |
| 0 to 23 | 24 curves |
| 24 to 34 | 11 junctions |
| 35 to 100 | 66 straight pieces and road ends |

The tiles at offsets 50, 67, 83 and 100 have no road connections in the table and are never laid.

The count runs across tile-set boundaries, so the three groups can sit in consecutive tile sets. A tile out of place gives the generator the wrong connection points for the piece it lays there.

The generator opens each road network on a junction from [`DirtRoadJunction`](/keys/dirtroadjunction/), which must point at offset 24 of this run.

Two other dirt road roles play no part in laying the flat pieces:

- The eight ramp pieces from [`DirtRoadSlopes`](/keys/dirtroadslopes/) follow the 101 in the table but are never laid.
- [`DirtRoadStraight`](/keys/dirtroadstraight/) has no effect, since the straight pieces are found through this role.
