---
key: GDIPowerTurbine
summary: Seeds the first side's PowerTurbine.
see_also: [PowerTurbine, "system:ai-base-building"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[General]
GDIPowerTurbine=GAPOWRUP
```

The value becomes the [`PowerTurbine`](/keys/powerturbine/) of the first side in the rules' [`[Sides]`](/formats/rules-registries/) list, in each rules file that sets this key. A `PowerTurbine=` in that side's own section of the same file overrides it. A file that omits this key leaves the side's value alone. No key seeds a turbine for any other side, and nothing else reads this key.
