---
key: InfantryReserve
summary: Parsed cash threshold for infantry production that the engine never uses.
no_effect: true
see_also: ["system:ai-team-production", InfantryBaseMult]
when_omitted:
  kind: value
  value: "2000"
---

A computer house never holds money back before ordering infantry. It picks the next infantryman from [the demand its teams leave unfilled](/systems/ai-team-production/#production-demand). Money matters only in that it cannot order a type that costs more than it can spend.
