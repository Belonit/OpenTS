---
key: BestLowPowerBuildRateCoefficient
summary: Parsed best-case low-power build coefficient that the engine never uses.
no_effect: true
see_also: ["system:power"]
when_omitted:
  kind: value
  value: ".75"
---

The mildest production slowdown a power shortfall can cause is fixed in the engine at a multiplier of `0.75`, the same as this key's default. [The production table](/systems/power/#production) lists the multipliers that apply.
