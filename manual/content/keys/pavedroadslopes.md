---
key: PavedRoadSlopes
summary: Tile set of paved road ramp pieces that nothing reads.
no_effect: true
see_also: [PavedRoads, DirtRoadSlopes]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

Nothing in the game uses this role, and the [random map generator](/systems/map-generation/#settlements) never lays a paved road slope. A map can still use these tiles to carry a road up a ramp. Their terrain type then comes from the tile artwork, as for any other tile. [`DirtRoadSlopes`](/keys/dirtroadslopes/) is the dirt road counterpart.
