---
key: WorstLowPowerBuildRateCoefficient
summary: Parsed worst-case low-power build coefficient that the engine never uses.
no_effect: true
see_also: ["system:power"]
when_omitted:
  kind: value
  value: ".3"
---

The slowest production a power shortfall can cause is fixed in the engine at a multiplier of `0.5`, or at [`MinProductionSpeed`](/keys/minproductionspeed/) when that is higher. [The production table](/systems/power/#production) lists the multipliers that apply.
