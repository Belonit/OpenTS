---
key: Cost
scope: aircrafttype
label: Object price
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "0"
---

The credits charged to produce one object of the type, before the owner's country and difficulty multipliers scale it. Other figures are worked out from this price, among them the [base build time](/keys/buildspeed/), the [experience a kill is worth](/systems/veterancy/#earning-experience), the score a kill earns, and the [price of one repair step](/systems/repair/#the-cost-of-one-step).

Repairing an aircraft uses its full written price. An aircraft's price also lowers the repair price of a structure that comes with it, either as the structure's [`FreeUnit=`](/keys/freeunit/) or through the [`PadAircraft=`](/keys/padaircraft/) list. [What a structure gives away](/keys/cost/#what-a-structure-gives-away) gives the exact deduction and its effect on the structure's purchase price.
