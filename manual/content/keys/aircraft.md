---
key: Aircraft
summary: Parsed intelligence level that the engine never uses.
no_effect: true
see_also: ["system:ai-team-production", IQ, Harvester]
when_omitted:
  kind: value
  value: "4"
---

No intelligence level gates aircraft production. A computer house orders aircraft only to fill places in its teams, through [the same demand count it uses for vehicles and infantry](/systems/ai-team-production/#production-demand), and that count ignores the house's [`IQ`](/keys/iq/). [`Harvester`](/keys/harvester/#scope-global-rules) is the `[IQ]` key that gates a rebuild: it sets the IQ at which a computer house starts replacing lost harvesters.
