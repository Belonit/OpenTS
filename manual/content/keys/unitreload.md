---
key: UnitReload
summary: Makes the building rearm the object docked with it, one ammunition point at a time.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "no"
---

`UnitReload=yes` makes a building rearm the object docked with it. The object gains one point of [`Ammo`](/keys/ammo/) every [`ReloadRate`](/keys/reloadrate/) interval until its ammunition is full. Rearming is free and repairs nothing.

A helipad rearms the aircraft that land on it only if it also sets this flag.

A building with both `UnitReload=yes` and [`UnitRepair=yes`](/keys/unitrepair/) repairs and never gives the one-point rearming, because the building runs only [the first service its flags match](/systems/repair/#unitreload-is-a-different-service). Such a depot still [refills a `ManualReload=yes` object for free](/systems/repair/#what-a-depot-does-for-free).

When another aircraft asks to dock, a parked aircraft with full ammunition moves to a nearby cell to make room for it. Otherwise the parked object keeps its place and the building refuses the newcomer.
