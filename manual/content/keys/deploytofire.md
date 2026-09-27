---
key: DeployToFire
summary: Makes a vehicle attack by deploying into its DeploysInto structure on buildable ground, and stops a human player's vehicle from searching for targets.
see_also: ["DeploysInto", "NoMovingFire", "Buildable"]
when_omitted:
  kind: value
  value: "no"
---

A vehicle with the flag never fires its own weapon. Once its target is in range and it is ready to fire or needs only to turn, it deploys into its [`DeploysInto`](/keys/deploysinto/) structure instead, and the structure takes over the target. The deploy follows the same rules as a deploy order, so it fails if the structure cannot be placed there.

```ini title="rules.ini"
[MYSIEGETANK] ; a UnitType registered in [VehicleTypes]
DeployToFire=yes
DeploysInto=MYSIEGEGUN ; a BuildingType registered in [BuildingTypes]
```

Give the vehicle a `DeploysInto` structure, no passenger capacity and no harvesting role. The flag starts the vehicle's ordinary deploy action, so:

- a vehicle with [`Passengers`](/keys/passengers/) above `0` unloads its passengers instead of deploying;
- a [`Harvester=yes`](/keys/harvester/#scope-unittype) or [`Weeder=yes`](/keys/weeder/#scope-unittype) vehicle runs its unload action instead;
- a vehicle with no `DeploysInto` structure never attacks, except that an [`IsMobileEMP=yes`](/keys/ismobileemp/) one releases its pulse once fully charged.

The vehicle deploys only from a cell that meets **All of:**

- it has no ramp;
- it holds no structure;
- its land type sets [`Buildable=yes`](/keys/buildable/).

From any other cell, the vehicle drives to a qualifying cell before it deploys. It picks one within its weapon range of the target and no more than two cells farther from the target than it already is. If it finds no such cell it can reach, it gives up the target and moves to a cell near it.

A vehicle owned by a human player never searches for targets. It attacks what it is ordered to, and it can still [strike back](/systems/target-selection/#retaliation) at an enemy that damages it, unless its `DeploysInto` structure sets [`Artillary=yes`](/keys/artillary/). A computer-controlled vehicle keeps its ordinary target search.
