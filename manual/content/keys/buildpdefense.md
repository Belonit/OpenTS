---
key: BuildPDefense
summary: Parsed power-hungry defense list for a computer base that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", BuildDefense, IsBaseDefense]
when_omitted:
  kind: value
  value: ""
---

A computer house picks every base defense the same way, whatever the defense's power drain. [The defense planner](/systems/ai-base-building/#base-defenses) chooses by the category values of the types the house's country [may own](/keys/owner/). A planned structure's drain matters only when the house decides whether to [insert a power plant ahead of it](/systems/ai-base-building/#power-and-money-interventions).
