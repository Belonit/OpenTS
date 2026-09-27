---
key: GrowthRate
summary: Parsed rate that the engine never uses.
no_effect: true
see_also: ["system:tiberium", Growth]
when_omitted:
  kind: value
  value: "2"
---

The name suggests the time between Tiberium growth passes in minutes, but nothing reads the stored value.

Each Tiberium type times its own growth in frames. After every growth pass, the type waits its [`Growth`](/keys/growth/) delay before the next one, or 30% of that delay while the scenario's [`TiberiumGrows`](/keys/tiberiumgrows/) setting is on. The scenario's [`TiberiumGrowthEnabled`](/keys/tiberiumgrowthenabled/) switch decides whether any pass runs. [Growth](/systems/tiberium/#growth) explains which cells a pass ripens.
