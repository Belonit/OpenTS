---
key: AirstripLimit
summary: Parsed ceiling on airstrips that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", AirstripRatio, Helipad]
when_omitted:
  kind: value
  value: "5"
---

No computer base decision counts airstrips, so this ceiling limits nothing. [`AirstripRatio`](/keys/airstripratio/) has no effect either.
