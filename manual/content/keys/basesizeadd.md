---
key: BaseSizeAdd
summary: Parsed allowance over a rival base's size that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", AIBaseSpacing]
when_omitted:
  kind: value
  value: "3"
---

The engine never compares one house's base with another's, and no cap limits how far a computer base grows. A computer base's size follows from [the node list it builds from](/systems/ai-base-building/#building-the-plan) and from the ground its [placement search](/systems/ai-base-building/#choosing-a-spot) accepts.
