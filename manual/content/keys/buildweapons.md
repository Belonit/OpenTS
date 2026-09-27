---
key: BuildWeapons
summary: The war factories a computer house resolves a generic factory prerequisite to, in order of preference.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: ""
---

`BuildWeapons` lists the structures the game treats as war factories, in order of preference. A house's preferred war factory is the first entry its country [may own](/keys/owner/). The country is the one the house [acts as](/keys/actslike/). Owning any entry counts as owning a war factory.

A computer house uses the list in these decisions:

- **Base plan.** While [the base plan](/systems/ai-base-building/#building-the-plan) is assembled, a [`Prerequisite=FACTORY`](/keys/prerequisite/) is met only by the house's preferred war factory. That structure also moves to second place in the order the plan considers structures. If the country may own no entry, no type that needs `FACTORY` enters the plan.
- **Whether it can still earn.** A house that owns a refinery but no harvester can still earn money if any of these holds:
  - it owns a war factory and can afford a harvester;
  - it can afford a harvester and a war factory together;
  - it can afford a refinery.

  The war factory in the second case is priced as the preferred one, as the first entry when the country may own none, and at nothing when the list is empty. A house that cannot earn may [sell its base](/systems/ai-base-building/#power-and-money-interventions).
- **What a sale pays for.** A house selling its base raises money for a harvester if it owns a refinery and a war factory, and for a refinery otherwise.
- **Production while short of credits.** Outside a campaign, a house whose credits are below [`AIAlternateProductionCreditCutoff`](/keys/aialternateproductioncreditcutoff/) and that owns no war factory switches back to structures after each vehicle, infantryman or aircraft it produces.

The list also affects the deploy cursor. For a vehicle whose [`DeploysInto`](/keys/deploysinto/) names a listed structure, the cursor tests the site one cell northwest of the vehicle, which is where the structure is placed when the vehicle deploys. For a structure in neither this list nor [`BuildConst`](/keys/buildconst/), the cursor tests the vehicle's own cell instead.
