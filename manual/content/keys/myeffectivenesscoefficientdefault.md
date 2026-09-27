---
key: MyEffectivenessCoefficientDefault
summary: The MyEffectivenessCoefficient every object type falls back on.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "0"
---

A type that does not set [`MyEffectivenessCoefficient`](/keys/myeffectivenesscoefficient/) uses this value instead. A positive value makes the types that use it prefer candidates their warhead damages well. [The threat score](/systems/target-selection/#the-threat-score) shows how it combines with the other coefficients.

Each rules layer reads `[General]` before the object types, so the value reaches every type whose section appears in the same file. A type takes the value only while its coefficient is `0`:

- An explicit `MyEffectivenessCoefficient=0` counts as unset, so a later rules layer can replace it with this value. The [`MyEffectivenessCoefficient`](/keys/myeffectivenesscoefficient/) page shows how to keep a `0`.
- A type that already took a nonzero value, from its own section or from an earlier default, keeps it when a later layer changes this default.
