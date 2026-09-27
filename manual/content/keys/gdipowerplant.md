---
key: GDIPowerPlant
summary: Seeds the first side's RegularPowerPlant.
see_also: [RegularPowerPlant, "system:ai-base-building"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[General]
GDIPowerPlant=GAPOWR
```

The value becomes the [`RegularPowerPlant`](/keys/regularpowerplant/) of the first side in the rules' [`[Sides]`](/formats/rules-registries/) list, in each rules file that sets this key. A `RegularPowerPlant=` in that side's own section of the same file overrides it. A file that omits this key leaves the side's value alone. [`NodRegularPower`](/keys/nodregularpower/) does the same for the second side, and nothing else reads this key.
