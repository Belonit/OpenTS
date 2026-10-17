---
key: BestLowPowerBuildRateCoefficient
summary: The production multiplier of a house that is only slightly short of power.
see_also: ["system:power", "WorstLowPowerBuildRateCoefficient", "MinProductionSpeed"]
when_omitted:
  kind: value
  value: ".75"
---

A house short of power whose power fraction is above this value builds with this value as its production multiplier. Its build time is divided by the multiplier, so the default `.75` makes a build take a third longer. Below this value the multiplier follows the power fraction, down to [`WorstLowPowerBuildRateCoefficient`](/keys/worstlowpowerbuildratecoefficient/). [The production table](/systems/power/#production) lists every step.
