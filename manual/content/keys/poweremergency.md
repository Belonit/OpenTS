---
key: PowerEmergency
summary: Parsed power fraction that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", "system:power", PowerSurplus]
when_omitted:
  kind: value
  value: ".75"
---

A computer house never sells structures to recover power. Instead, a house that is not following a map plan [builds a power plant first](/systems/ai-base-building/#power-and-money-interventions) whenever its next structure would push its drain above its power output.
