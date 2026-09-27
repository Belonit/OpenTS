---
key: NodGateTwo
summary: The BuildingType that joins a Nod wall running north to south.
see_also: ["system:walls-and-gates", "Gate"]
when_omitted:
  kind: value
  value: none
---

The named BuildingType connects to Nod walls (`NAWALL` in the stock rules) along the north-south axis. A Nod wall cell directly north or south of it joins it, so a north-south wall run passes through the structure. A wall cell directly east or west of it does not join it, and the wall ends there. Brick and sandbag walls never join it; [`GDIGateOne`](/keys/gdigateone/) and [`GDIGateTwo`](/keys/gdigatetwo/) connect those. [Connection frames](/systems/walls-and-gates/#connection-frames) compares all the gate keys.

Naming the type also lets it be placed over Nod wall cells that the placing house owns, whatever their damage. An ordinary wall BuildingType can replace only a damaged segment.

When the type is placed or taken off the map, the wall cells at both ends of its run update their connections. These are the cell just north of its origin cell and the cell three cells south of it. The offsets assume a gate three cells long, so a type of any other length updates the wrong cells.

This key and [`Gate=yes`](/keys/gate/) are independent. `Gate=yes` gives the type its opening door and can remove the house's walls from its footprint when it is placed, under the conditions in [Placing a gate](/systems/walls-and-gates/#placing-a-gate). This key gives it the wall connection. A type can have either without the other.
