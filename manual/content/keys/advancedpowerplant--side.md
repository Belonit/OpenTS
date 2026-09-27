---
key: AdvancedPowerPlant
scope: side
label: Side advanced power plant
see_also: [RegularPowerPlant, PowerTurbine, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The second side takes NodAdvancedPower as each rules file sets it; every other side names none.
---

```ini title="rules.ini"
[Nod]
AdvancedPowerPlant=NAAPWR
```

The BuildingType a computer house playing for this side inserts to cover a [power shortfall](/systems/ai-base-building/#power-and-money-interventions), once the structures the house owns meet this type's [`Prerequisite`](/keys/prerequisite/) list. Until then the house falls back to its side's [`RegularPowerPlant`](/keys/regularpowerplant/), or to [`BuildPower`](/keys/buildpower/) when the side names none, as `RegularPowerPlant` describes. When the side also names a [`PowerTurbine`](/keys/powerturbine/), the house tries the turbine before this plant.

Writing `<none>` clears a value set earlier, by `[General]` or by an earlier rules file.

When the computer takes over a departed player's house, its plan can gain nodes for standing structures of this type, under the conditions [`RegularPowerPlant`](/keys/regularpowerplant/) describes.
