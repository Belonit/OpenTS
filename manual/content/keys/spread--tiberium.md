---
key: Spread
scope: tiberium
label: Spread delay
when_omitted:
  kind: value
  value: "0"
  note: A delay of zero, which gives the type a spread pass on every frame.
---

After each [spread pass](/systems/tiberium/#spread), the type waits this many frames before the next one, whether or not any cell spread. A lower value makes the type's fields spread faster. Fast growth from [`TiberiumGrows`](/keys/tiberiumgrows/#scope-scenarios) does not shorten this wait.

No spread pass runs while the scenario's [`TiberiumGrowthEnabled`](/keys/tiberiumgrowthenabled/) switch is off, and no cell spreads while the scenario sets [`TiberiumSpreads=no`](/keys/tiberiumspreads/), whatever this value is.
