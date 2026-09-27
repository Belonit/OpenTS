---
key: GDIGateOne
summary: The BuildingType that joins a brick or sandbag wall running east to west.
see_also: ["system:walls-and-gates", "Gate"]
when_omitted:
  kind: value
  value: none
---

The named BuildingType connects to brick and sandbag walls (`GAWALL` and `GASAND` in the stock rules) along the east-west axis. A wall cell directly east or west of it joins it, so an east-west wall run passes through the structure. A wall cell directly north or south of it does not join it, and the wall ends there. [Connection frames](/systems/walls-and-gates/#connection-frames) compares this with the other gate keys and [`WallTower`](/keys/walltower/).

Naming the type also lets it be placed over brick and sandbag wall cells that the placing house owns, whatever their damage. An ordinary wall BuildingType can replace only a damaged segment.

When the type is placed or taken off the map, the wall cells at both ends of its run update their connections. These are the cell just west of its origin cell and the cell three cells east of it. The offsets assume a gate three cells long, so a type of any other length updates the wrong cells.

This key and [`Gate=yes`](/keys/gate/) are independent. `Gate=yes` gives the type its opening door and can remove the house's walls from its footprint when it is placed, under the conditions in [Placing a gate](/systems/walls-and-gates/#placing-a-gate). This key gives it the wall connection. A type can have either without the other.
