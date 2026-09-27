---
key: AIUseTurbineUpgradeProbability
summary: The chance that a computer house answers a power shortfall with a power turbine upgrade instead of a new power plant.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: "1"
---

The value is a fraction of 1. Each time a computer house must [add power before its next structure](/systems/ai-base-building/#power-and-money-interventions), it draws a random number and chooses the turbine when the draw falls below this value.

The draw happens only when both of these hold:

- the side the house acts as names a [`PowerTurbine`](/keys/powerturbine/) and a [`RegularPowerPlant`](/keys/regularpowerplant/);
- the house owns one of those regular power plants with a free upgrade slot.

At `1` the turbine is chosen whenever both hold, and at `0` it is never chosen. When the turbine is not chosen, the house builds the side's advanced or regular power plant instead.

```ini title="rules.ini"
[General]
AIUseTurbineUpgradeProbability=0.5  ; example: a turbine on about half the draws
```
