---
key: NodAdvancedPower
summary: Seeds the second side's AdvancedPowerPlant.
see_also: [AdvancedPowerPlant, "system:ai-base-building"]
when_omitted:
  kind: value
  value: none
---

When a rules file sets this key, its value becomes the [`AdvancedPowerPlant`](/keys/advancedpowerplant/) of the second side listed in [`[Sides]`](/formats/rules-registries/). An `AdvancedPowerPlant=` in that side's section of the same file overrides it. A file that omits this key leaves the side's value as it was. Nothing else reads the key.

No `[General]` key does the same for the first side; set `AdvancedPowerPlant=` in its section instead.
