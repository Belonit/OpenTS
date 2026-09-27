---
key: GDIBaseDefenseCoefficient
summary: Seeds the first side's AIBaseDefenseCoefficient.
see_also: [AIBaseDefenseCoefficient, "system:ai-base-building"]
when_omitted:
  kind: value
  value: "1"
---

When a rules file sets this key, its value becomes the [`AIBaseDefenseCoefficient`](/keys/aibasedefensecoefficient/) of the first side listed in [`[Sides]`](/formats/rules-registries/). An `AIBaseDefenseCoefficient=` in that side's section of the same file overrides it. A file that omits this key leaves the side's coefficient as it was. Nothing else reads the key.
