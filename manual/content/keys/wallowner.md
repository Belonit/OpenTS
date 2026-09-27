---
key: WallOwner
summary: Whether the country's buildings can claim the walls placed with the map.
see_also: ["system:walls-and-gates"]
when_omitted:
  kind: value
  value: "yes"
---

Walls placed with the map start with no owner. Once the map has loaded, each wall cell goes to the owner of the nearest building on the map whose country has `WallOwner=yes`. The buildings of a `WallOwner=no` country never claim map walls.

The search covers the whole map, with no radius limit. At equal distance, the building created first wins. If no building qualifies, the walls stay unowned. An unowned wall cannot be sold and is not an anchor for the [automatic gap fill](/systems/walls-and-gates/#filling-the-gap-to-the-next-wall).

Map walls are assigned once, at load, and keep that owner when buildings are later placed, captured or lost. In skirmish and multiplayer, the players' starting units and bases are created after the walls are assigned, so they never claim a map wall.

A wall a player builds belongs to that player's house.
