---
key: Growth
summary: Game frames a Tiberium type waits between growth passes.
see_also: ["system:tiberium", "GrowthPercentage", "TiberiumGrows"]
when_omitted:
  kind: value
  value: "0"
  note: A delay of zero, which gives the type a growth pass on every frame.
---

After each [growth pass](/systems/tiberium/#growth), the type waits this many frames before the next one, whether or not any cell grew. A lower value makes the type's fields ripen faster.

When [`TiberiumGrows`](/keys/tiberiumgrows/#scope-scenarios) turns on fast growth, the wait is 30% of this value, rounded down. That page explains when fast growth applies. No other setting shortens or lengthens the wait.

No growth pass runs while the scenario's [`TiberiumGrowthEnabled`](/keys/tiberiumgrowthenabled/) switch is off, whatever this value is.
