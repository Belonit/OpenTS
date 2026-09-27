---
key: WaterBound
scope: buildingtype
label: Water-bound structure
see_also: [Buildable, PlaceAnywhere, "system:base-adjacency"]
when_omitted:
  kind: value
  value: "no"
---

`WaterBound=yes` lets a structure stand on land types that floating objects can cross, in place of land types marked buildable. The setting chooses which ground test every cell of the foundation must pass. The same test decides where a player or computer house may place the structure, where a vehicle may deploy into it, and what the placement cursor shows.

| Setting | What each foundation cell must satisfy |
| --- | --- |
| `WaterBound=no` | Not a bridge, not a cell under a bridge, no ramp, and a land type with [`Buildable=yes`](/keys/buildable/) |
| `WaterBound=yes` | A land type with a `Float=` movement cost above zero. `Float=` is set in the land type's section, beside `Buildable=` |

A water-bound structure is never tested for `Buildable=`, bridges or ramps. Which land types have a `Float=` cost above zero is the only ground rule it follows.

For an ordinary structure, both settings share the remaining tests. Each cell must hold no other object and lie inside the playable area. An overlay in the cell blocks the structure unless it has [`BuildableOver=yes`](/keys/buildableover/) and is not a wall. Walls and gates follow the cell rules in [Walls, gates and wall towers](/systems/walls-and-gates/), and laser fences and their posts follow those under [`LaserFence`](/keys/laserfence/).
