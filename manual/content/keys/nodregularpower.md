---
key: NodRegularPower
summary: Seeds the second side's RegularPowerPlant.
see_also: [RegularPowerPlant, "system:ai-base-building"]
when_omitted:
  kind: value
  value: none
---

Each rules file that sets this key copies its value into the [`RegularPowerPlant`](/keys/regularpowerplant/) of the second side in the rules' [`[Sides]`](/formats/rules-registries/) list. A `RegularPowerPlant=` in that side's own section of the same file then overrides it. [`GDIPowerPlant`](/keys/gdipowerplant/) does the same for the first side. Nothing else reads this key.
