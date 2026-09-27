---
key: RepairStep
summary: The strength one repair step restores to a structure, vehicle or aircraft.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "5"
---

Each repair step restores this many strength points to a structure, vehicle or aircraft. It applies to the wrench on a structure and to a service depot repairing a vehicle or aircraft. Infantry use [`IRepairStep`](/keys/irepairstep/) instead. A vehicle or aircraft with [Tiberium healing](/systems/repair/#self-healing) also regains this many points per healing tick.

The value also sets how many steps a full repair takes: `Strength / RepairStep`. The object's price is split across those steps to give the [cost of one step](/systems/repair/#the-cost-of-one-step). A larger value gives fewer, larger and dearer steps. A full repair then finishes sooner, but costs roughly the same in total.

:::danger[Keep `RepairStep` between `1` and the smallest repairable `Strength`]
Keep the value above `0` and no larger than the [`Strength`](/keys/strength/) of any structure, vehicle or aircraft that can be repaired. A value of `0`, or one larger than an object's `Strength`, crashes the game on that object's first repair step, under the wrench or at a depot.
:::
