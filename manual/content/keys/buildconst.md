---
key: BuildConst
summary: The construction yard BuildingTypes; a building of any listed type is a construction yard.
see_also: ["system:ai-base-building"]
when_omitted:
  kind: value
  value: ""
---

Structures of the listed types are a house's construction yards for structure production and for every effect below. [`ConstructionYard=yes`](/keys/constructionyard/) on an unlisted type gives only the behaviors that page lists.

A house can build structures only while it owns a listed yard that acts for a country in the structure's [`Owner`](/keys/owner/) list, as [Ownership](/systems/production/#ownership) describes. A listed yard also produces only for the country it [acts as](/keys/actslike/), and it keeps that country when captured, so a captured yard goes on building its original owner's structures. [`MultiMCV=yes`](/keys/multimcv/) removes both restrictions.

A computer house starts structures from its base plan only while it owns a listed yard. The list also shapes [a generated plan](/systems/ai-base-building/#building-the-plan):

- The plan starts with the first candidate, in `[BuildingTypes]` order, that the list names.
- A [`Prerequisite`](/keys/prerequisite/) naming a listed type always counts as met. This also holds when the house picks a base defense or an advanced power plant.
- The planner never inserts [a power plant](/systems/ai-base-building/#power-and-money-interventions) ahead of a listed yard.

A vehicle whose [`DeploysInto`](/keys/deploysinto/) names a listed type is an MCV to a computer house:

- Outside a campaign game, a base-building computer house that owns no listed yard sends its MCVs on the hunt mission.
- On the hunt mission, a computer house's MCV drives to open ground and deploys there instead of attacking.
- A base-building computer house's MCV that is on guard tries to deploy where it stands. If the spot is refused, the MCV goes on the hunt mission outside a campaign game; in a campaign game it stays on guard and tries again.

The list also decides where the [Center Base](/commands/centerbase/) command goes, whether the player hears the [low-power warning](/systems/power/#player-feedback), which vehicles the computer values as MCVs when it [aims an ion cannon](/keys/aiioncannonmcvvalue/), and where a house that [passes to the computer](/systems/ai-base-building/#where-the-plan-comes-from) centers its new plan.

:::caution[Building lists are split on commas alone]
Names are matched without regard to case. The value is trimmed at its ends, but the split is on commas alone, so `GAPOWR, NAPOWR` looks for a type whose ID begins with a space. A name that matches no BuildingType ID adds a new BuildingType with that name. When no section of that name exists, no house may own the new type. When one does, such as a UnitType's section, it is read as a BuildingType, `Owner` included.

To empty a list, write `none`. A key written with an empty value keeps the list an earlier file set. Every building list in `[AI]` is read this way, and a scenario with an `[AI]` section replaces each list it names.
:::
