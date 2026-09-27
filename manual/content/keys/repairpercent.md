---
key: RepairPercent
summary: The share of an object's price that a full repair charges.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: ".25"
---

```ini title="rules.ini"
[General]
RepairPercent=.5   ; a full repair charges about half the object's price
```

Each repair step costs `(Cost / (Strength / RepairStep)) * RepairPercent` credits, and never less than one credit. It applies to the wrench on a structure and to a service depot repairing a vehicle or aircraft. A hospital heals infantry for free, so infantry never pay it.

A full repair costs roughly `RepairPercent` of the object's price, not exactly:

- Each division and the multiplication drop fractions of a credit, which usually makes a repair slightly cheaper. At the defaults, a structure costing 1000 with [`Strength=400`](/keys/strength/) pays 3 credits for each of its 80 steps, 240 credits in total instead of 250.
- The one-credit minimum makes a cheap object with high `Strength` dearer. A structure costing 100 with `Strength=1000` pays the minimum on all 200 of its steps, twice what it cost to build.

[The cost of one step](/systems/repair/#the-cost-of-one-step) shows where each truncation happens and which price counts as `Cost`.
