---
key: PowerTurbine
scope: side
label: Side power turbine
see_also: [RegularPowerPlant, AIUseTurbineUpgradeProbability, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The first side takes GDIPowerTurbine as each rules file sets it; every other side names none.
---

```ini title="rules.ini"
[GDI]
PowerTurbine=GAPOWRUP
```

The power plant upgrade a computer house playing for this side prefers when it inserts a plant to cover a [power shortfall](/systems/ai-base-building/#power-and-money-interventions). The house picks the turbine when both of these hold:

- it owns a structure of its side's [`RegularPowerPlant`](/keys/regularpowerplant/) type with a free upgrade slot;
- a random draw passes [`AIUseTurbineUpgradeProbability`](/keys/aiuseturbineupgradeprobability/).

Otherwise it falls back to the side's [`AdvancedPowerPlant`](/keys/advancedpowerplant/) or `RegularPowerPlant`. A side that names no `RegularPowerPlant` never picks the turbine.

When the computer takes over a departed player's house, its plan can gain one turbine for each upgrade already on the house's `RegularPowerPlant` structures. Each turbine goes on the plant it upgrades, and enters the plan only at a point where the plan would otherwise run short of power.

Writing `<none>` clears a value set earlier, by `[General]` or by an earlier rules file.
