---
key: Weeder
scope: unittype
label: Vein harvester
see_also: ["system:veins", "system:tiberium", "Harvester", "Storage", "Dock"]
when_omitted:
  kind: value
  value: "no"
---

`Weeder=yes` makes the vehicle a vein harvester. It collects mature veins from cells of the [Weeds](/reference/enums/land-type/) land type, up to its [`Storage`](/keys/storage/) capacity. When it returns without an order, it unloads at a [`Weeder=yes`](/keys/weeder/#scope-buildingtype) building of its house whose type is in its [`Dock`](/keys/dock/) list. Each unload adds to the house's [weed pool](/systems/veins/#the-weed-pool).

A weeder starts harvesting when it is placed on the map, including when it leaves a factory or a repair bay. When it later goes idle, it resumes harvesting if its house is computer-controlled or it is standing on veins. A player-owned weeder that goes idle anywhere else takes guard until it is given another order. An armed one may take area guard instead, as other armed vehicles do.

[Weed harvesting](/systems/veins/#weed-harvesting) covers the patch search and the load and unload cycles. [Tiberium harvesting](/systems/tiberium/#harvesting) covers the harvest mission that weeders and Tiberium harvesters share.

```ini title="rules.ini"
[MYWEEDEATER] ; a UnitType registered in [VehicleTypes]
Weeder=yes
```
