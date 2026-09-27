---
key: RefineryRatio
summary: Parsed refinery share of a computer base that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", RefineryLimit, BuildRefinery]
when_omitted:
  kind: value
  value: ".16"
---

No step of computer base planning reserves a share of the base for refineries. When the engine generates a computer house's plan, the refineries in it are set as [the plan is built](/systems/ai-base-building/#building-the-plan). The first [`BuildRefinery`](/keys/buildrefinery/) entry whose owners include the country the house [acts as](/keys/actslike/) enters like any other candidate structure, and the house's difficulty slot decides how many extra copies follow it. A plan the scenario supplies keeps the refineries the scenario lists.
