---
key: MinProductionSpeed
summary: The floor the low-power production multiplier is held to.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: ".5"
---

This value sets the slowest a power shortfall can make production. A house's build time is divided by a production multiplier that falls as its power drops, and the multiplier is never lower than this value. A multiplier of `.5` doubles build time, and `1` removes the low-power penalty entirely.

A value at or below [`WorstLowPowerBuildRateCoefficient`](/keys/worstlowpowerbuildratecoefficient/) changes nothing, because [the production table](/systems/power/#production) never drops below that value.

:::caution[Values above 1 speed up every house]
The floor also applies at full power. With `MinProductionSpeed=2`, every house builds in half the time, whether or not it is short of power.
:::
