---
key: HelipadRatio
summary: Parsed helipad share of a computer base that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", HelipadLimit, Helipad]
when_omitted:
  kind: value
  value: ".12"
---

No share of a computer base is reserved for helipads. The only helipad count comes from [assembling the base plan](/systems/ai-base-building/#building-the-plan), where each [`Helipad=yes`](/keys/helipad/) type the plan takes is added a random number of extra times.
