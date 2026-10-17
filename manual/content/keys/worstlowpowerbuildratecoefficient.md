---
key: WorstLowPowerBuildRateCoefficient
summary: The lowest production multiplier a power shortfall can impose before MinProductionSpeed applies.
see_also: ["system:power", "BestLowPowerBuildRateCoefficient", "MinProductionSpeed"]
when_omitted:
  kind: value
  value: ".3"
---

A house whose power fraction is below this value builds with this value as its production multiplier. Its build time is divided by the multiplier. [`MinProductionSpeed`](/keys/minproductionspeed/) then raises any multiplier below it, so with the default `MinProductionSpeed=.5` the default `.3` never applies. [The production table](/systems/power/#production) lists every step.
