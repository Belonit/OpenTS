---
key: NODBarracks
summary: Gives the structure a preferred door cell for leaving objects, two east and two south of its foundation's north-west corner.
see_also: [GDIBarracks, ExitCoord, "system:production"]
when_omitted:
  kind: value
  value: "no"
---

A `NODBarracks=yes` structure lets objects out through a door cell when it can: the cell two east and two south of the north-west corner of its foundation. An object that leaves by the door cell is shifted by [`ExitCoord`](/keys/exitcoord/) where it appears, so it can start in a doorway.

The door cell is used only when it lies inside the [playfield](/glossary/#playable-area) and the leaving object could enter it. Otherwise the structure falls back to the ordinary exit cells around its foundation.

Every object that leaves through an exit cell starts inside the foundation, at the center of the foundation cell nearest the exit cell, and then walks out onto it. `ExitCoord` is added to that starting point only when the exit cell is the door cell.

The flag changes only where objects leave. It does not decide what the structure produces, and it does not make the structure satisfy a `BARRACKS` prerequisite. [Leaving the factory](/systems/production/#leaving-the-factory) covers which structures let objects out through an exit cell; a [`WeaponsFactory=yes`](/keys/weaponsfactory/) structure, a refinery and a weeder never do.

A repair bay with this flag also prefers the door cell when it sends a repaired vehicle away, unless a computer house has already given the vehicle somewhere to go. The vehicle drives there from the bay, so `ExitCoord` plays no part.

:::note[Both barracks flags on one structure]
[`GDIBarracks=yes`](/keys/gdibarracks/) is tested first. A structure with both flags uses the GDI door cell, one cell further west, and falls back to this one only when that cell is outside the playfield or blocked.
:::
