---
key: Harvester
scope: unittype
label: Tiberium harvester
see_also: ["system:tiberium", "Storage", "Dock", "Weeder"]
when_omitted:
  kind: value
  value: "no"
---

The vehicle harvests Tiberium on its own. It fills its [`Storage`](/keys/storage/) from Tiberium cells and unloads at a [`DockUnload=yes`](/keys/dockunload/) building from its [`Dock`](/keys/dock/) list. [Harvesting](/systems/tiberium/#harvesting) covers the search, load, and unload cycle.

:::caution[Do not also set `Weeder=yes`]
A vehicle with both this flag and [`Weeder=yes`](/keys/weeder/#scope-unittype) looks for veins when it sets out but loads only on Tiberium ground. There it adds one or two units to its first Tiberium compartment each cycle and leaves the cell's Tiberium untouched.
:::
