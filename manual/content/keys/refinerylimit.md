---
key: RefineryLimit
summary: Parsed ceiling on refineries that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", RefineryRatio, BuildRefinery]
when_omitted:
  kind: value
  value: "4"
---

No step of computer base planning counts refineries against a limit. When the engine generates a computer house's plan, the refineries in it are set as [the plan is built](/systems/ai-base-building/#building-the-plan). The first [`BuildRefinery`](/keys/buildrefinery/) entry whose owners include the country the house [acts as](/keys/actslike/) enters like any other candidate structure, and the house's difficulty slot decides how many extra copies follow it. A plan the scenario supplies keeps the refineries the scenario lists. A house that runs out of money can also insert a refinery into its plan, as [power and money interventions](/systems/ai-base-building/#power-and-money-interventions) describes.
