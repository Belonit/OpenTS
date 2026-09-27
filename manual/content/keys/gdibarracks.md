---
key: GDIBarracks
summary: Gives the structure a preferred exit cell one east and two south of its north-west corner, and starts objects leaving through it at the ExitCoord offset.
see_also: [NODBarracks, ExitCoord, "system:production"]
when_omitted:
  kind: value
  value: "no"
---

The structure gets a door cell one east and two south of its foundation's north-west corner. Whenever the structure looks for a cell to send an object out to, it tries the door cell first. The door cell is used if it lies inside the playfield and the object can enter it. Otherwise the structure falls back to the exit cells its foundation normally offers.

An object a factory lets out through any exit cell starts inside the foundation, one cell back from the exit cell along each axis on which that cell lies outside the foundation, and then walks out. When the exit cell is the door cell, [`ExitCoord`](/keys/exitcoord/) is added to that start, so the object appears in the doorway instead of at the middle of a cell.

The flag only sets the door cell. It does not decide what the structure produces, and it does not satisfy a `BARRACKS` prerequisite. [Leaving the factory](/systems/production/#leaving-the-factory) covers which factories let objects out this way. A [`WeaponsFactory=yes`](/keys/weaponsfactory/) structure, a refinery and a weeder use their own exits and never try the door cell.

A repair bay with the flag sends a repaired vehicle toward the door cell first, unless the vehicle belongs to a computer house and has a destination of its own. The vehicle drives there, so `ExitCoord` plays no part.

:::note[Both barracks flags may sit on one structure]
The door cells are tried in order, this one first. A structure with both prefers this door cell and falls back to the [`NODBarracks=yes`](/keys/nodbarracks/) cell one further east. `ExitCoord` is applied to whichever of the two was taken.
:::
