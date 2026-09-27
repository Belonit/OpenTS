---
key: GDIGateTwo
summary: The BuildingType that joins a brick or sandbag wall running north to south.
see_also: ["system:walls-and-gates", "Gate"]
when_omitted:
  kind: value
  value: none
---

The named BuildingType connects brick and sandbag walls (`GAWALL` and `GASAND` in stock rules) that run north to south through it. While the structure is standing, the [connection logic](/systems/walls-and-gates/#connection-frames) treats it as a wall segment for its northern and southern neighbors only. A wall that meets it from the east or west ends at it.

The named type can also be placed on a brick or sandbag wall segment that the same house owns, whatever the segment's damage.

Placing the structure, and taking it off the map, refreshes the wall frames around two cells: one cell north of its origin and three cells south of it. That reaches the wall just past each end of a gate two to four cells long. Past the southern end of a longer gate, or of a one-cell gate, the wall keeps its old frame.

The key does not need [`Gate=yes`](/keys/gate/), and `Gate=yes` does not need the key. `Gate=yes` supplies the opening and closing, and removes walls under the footprint at placement under the conditions in [Placing a gate](/systems/walls-and-gates/#placing-a-gate). This key supplies only the wall connection.
