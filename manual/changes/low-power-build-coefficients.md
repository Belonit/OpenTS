---
title: Low-power build coefficients take effect
category: fix
release: 0.2.0
targets:
- type: key
  id: BestLowPowerBuildRateCoefficient
  effect: changed
- type: key
  id: WorstLowPowerBuildRateCoefficient
  effect: changed
credit: [ZivDero, CCHyper]
---

`BestLowPowerBuildRateCoefficient=` and `WorstLowPowerBuildRateCoefficient=` used to be read and ignored, and a house short of power built at fixed multipliers of 0.75 and 0.5. They now set those two limits. With the shipped rules, production speed is unchanged, because `MinProductionSpeed=.5` still raises any multiplier below 0.5.

CCHyper is credited for the Vinifera option this follows.
