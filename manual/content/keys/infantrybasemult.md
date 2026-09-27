---
key: InfantryBaseMult
summary: Parsed multiplier on building count for infantry production that the engine never uses.
no_effect: true
see_also: ["system:ai-team-production", InfantryReserve]
when_omitted:
  kind: value
  value: "2"
---

No computer house compares its infantry with the size of its base. The infantry it builds is set by [production demand](/systems/ai-team-production/#production-demand): the places its teams still need filled, counted per InfantryType, less the soldiers it already has free to recruit.
