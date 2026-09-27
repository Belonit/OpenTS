---
key: DockUnload
summary: Lets a Tiberium harvester dock at a building and unload there.
see_also: ["system:tiberium", "Dock", "Refinery"]
when_omitted:
  kind: value
  value: "no"
---

A structure with `DockUnload=yes` accepts a [`Harvester=yes`](/keys/harvester/#scope-unittype) vehicle that asks to dock, and the harvester unloads its Tiberium there. No other flag admits a Tiberium harvester. [`Refinery=yes`](/keys/refinery/) places the dock point and plays the unloading animations, but it does not accept a harvester by itself.

A harvester never unloads at a structure that is also [`UnitRepair=yes`](/keys/unitrepair/) or [`Helipad=yes`](/keys/helipad/), because those flags decide first whether a docking vehicle is admitted.

The structure can still refuse a harvester, for example when the two houses are not allied both ways or another vehicle is already docked. [Unloading](/systems/tiberium/#unloading) lists the conditions and covers how a harvester picks a bay.

A [weed refinery](/systems/veins/) does not need this flag: [`Weeder=yes`](/keys/weeder/#scope-buildingtype) on the structure admits a weeder by itself.
