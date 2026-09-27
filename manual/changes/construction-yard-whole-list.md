---
title: Count every listed construction yard as one
category: fix
release: 0.2.0
targets:
- type: key
  id: BuildConst
  effect: changed
- type: system
  id: production
  effect: changed
- type: system
  id: superweapons
  effect: changed
- type: system
  id: ai-base-building
  effect: changed
credit: [ZivDero, AlexB]
---

`BuildConst` under `[AI]` in `rules.ini` lists the construction yard types. A structure of any listed type now counts as a construction yard, where only the first entry used to.

A house whose only yard was a later entry used to count as owning no yard. A computer house in that state built no structures, and a player in that state got no low power warning.

A later-entry yard could also build for any country. It is now limited to what its country may own, as a first-entry yard is, unless `MultiMCV=yes` is set.

Losing a construction yard to capture used to cancel the structure the player was placing whenever no first-entry yard remained. It is now canceled only when the player has no listed yard left.

A vehicle whose `DeploysInto` in its `rules.ini` section names any listed yard now counts as an MCV. A computer house sends it to find a site and deploy, and a computer house's ion cannon values it as an MCV when choosing a target. Its deploy cursor now shows no-deploy where the yard cannot be placed; it used to check the wrong cells.

A computer house's generated base plan now starts from a listed yard the house may own. The plan treats a prerequisite that names any listed yard as met, where only the first entry used to count. `BuildPower` under `[AI]` lists the power plants a computer house builds. When the house may own none of them, the plan now leaves out the power plant, where it used to add an empty entry. A starting plan of fewer than three structures is now the whole plan, where the game used to read past its end.

AlexB is credited for the ts-patches bundle that first read this list whole.
