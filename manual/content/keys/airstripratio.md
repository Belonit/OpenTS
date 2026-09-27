---
key: AirstripRatio
summary: Parsed airstrip share of a computer base that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", AirstripLimit, Helipad]
when_omitted:
  kind: value
  value: ".12"
---

No computer base decision counts airstrips or sizes a base by proportion, so this share has no effect. [`AirstripLimit`](/keys/airstriplimit/) has no effect either. A computer plan gets its landing pads from [`Helipad=yes`](/keys/helipad/) types, which receive extra copies while [the plan is assembled](/systems/ai-base-building/#building-the-plan).
