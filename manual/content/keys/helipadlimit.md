---
key: HelipadLimit
summary: Parsed ceiling on helipads that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", HelipadRatio, Helipad]
when_omitted:
  kind: value
  value: "5"
---

No maximum applies to the helipads a computer house builds. The number is decided when [the base plan is assembled](/systems/ai-base-building/#building-the-plan): each [`Helipad=yes`](/keys/helipad/) type the plan takes is added a random number of extra times.
