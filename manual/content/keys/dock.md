---
key: Dock
summary: BuildingTypes an object returns to for docking.
see_also: ["system:tiberium", "DockUnload", "Harvester"]
when_omitted:
  kind: value
  value: "none"
---

`Dock` lists the structure types a harvester unloads at and an aircraft lands at. When they choose a structure themselves, both pick only structures their house owns.

A harvester or weeder keeps its harvest mission only while its house owns at least one structure of a listed type. If the house owns none, or the list is empty, it switches to guard.

A harvester with a load to deliver heads for the nearest structure of any listed type that its house owns and that can take it. List order matters only between two equally distant structures, where the earlier type wins. [Unloading](/systems/tiberium/#unloading) covers the preference for a primary structure and when a harvester waits at a busy one instead.

A harvester or weeder sent to a structure of the first listed type enters it when that structure belongs to its house or to a house allied with it both ways.

An aircraft that returns to rearm or to land checks the listed types in order. It goes to a structure of the first listed type that can take it. It tries the next type only when no structure of the earlier types can. When no structure of any listed type can take it, it can instead land near one of its house's structures, where a structure of the first listed type counts as four times closer than any other. [`Landable`](/keys/landable/) covers when an aircraft lands.

The type listed first in the `Dock` of the first [`PadAircraft=`](/keys/padaircraft/) aircraft has the average pad-aircraft price deducted from its `Cost=` to form its reduced price. This does not apply with [`SeparateAircraft=yes`](/keys/separateaircraft/), or when that type's [`FreeUnit=`](/keys/freeunit/) is an aircraft. [What a structure gives away](/keys/cost/#what-a-structure-gives-away) explains what the reduced price changes.
