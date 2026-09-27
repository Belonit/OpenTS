---
key: Weeder
scope: buildingtype
label: Weed refinery
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: "no"
---

`Weeder=yes` makes a BuildingType a weed refinery, the structure where vein harvesters unload. A vein harvester is a vehicle whose UnitType sets [`Weeder=yes`](/keys/weeder/#scope-unittype). The building needs no [`DockUnload=yes`](/keys/dockunload/), but a harvester returning on its own looks only for types named in its [`Dock`](/keys/dock/) list, so name the refinery there.

```ini title="rules.ini"
[NAWAST]        ; Tiberium Waste Facility
Weeder=yes
```

The refinery takes one harvester at a time and refuses others while one is docking or unloading. It also refuses harvesters while it is switched off, being built or being sold. A harvester of another house may dock only when each house is allied with the other.

Each load goes into the weed pool of the harvester's house. [Docking and unloading](/systems/veins/#docking-and-unloading) covers the dock cell and the unloading rate, and [the weed pool](/systems/veins/#the-weed-pool) covers what the weed is used for.

A computer house adds such a type to [the base plan it generates](/systems/ai-base-building/#building-the-plan) only while the map has a [veinhole monster](/systems/veins/#veinhole-monsters). This affects only the computer's plan; a player can build the type on any map.
