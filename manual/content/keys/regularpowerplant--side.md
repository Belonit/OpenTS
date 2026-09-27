---
key: RegularPowerPlant
scope: side
label: Side power plant
see_also: [AdvancedPowerPlant, PowerTurbine, BuildPower, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The first side takes GDIPowerPlant and the second NodRegularPower, as each rules file sets them; any other side names no plant and inserts the first BuildPower entry the house's country may own.
---

```ini title="rules.ini"
[GDI] ; the section named after the side
RegularPowerPlant=GAPOWR
```

The BuildingType a computer house playing for this side inserts to cover a [power shortfall](/systems/ai-base-building/#power-and-money-interventions) when neither its [`PowerTurbine`](/keys/powerturbine/) nor its [`AdvancedPowerPlant`](/keys/advancedpowerplant/) qualifies. The house can pick the turbine only while it owns a structure of this type with a free upgrade slot.

Writing `<none>` clears a value set earlier, by `[General]` or by an earlier rules file. A side left with no plant inserts the first [`BuildPower`](/keys/buildpower/) entry the house's country may own instead.

When the computer takes over a departed player's house, its plan can gain a node for each standing structure whose type is any side's `RegularPowerPlant` or `AdvancedPowerPlant` and which the house can build. Each node goes at that structure's cell, and enters the plan only at a point where the plan would otherwise run short of power. The house's turbines are added the same way, as [`PowerTurbine`](/keys/powerturbine/) describes.

The section shares its name with the side. In the stock rules, `[GDI]` and `[Nod]` are therefore also the sections that describe the countries of those names.
