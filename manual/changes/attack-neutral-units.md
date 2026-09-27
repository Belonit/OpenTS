---
title: Auto-target neutrals on AttackNeutralUnits
category: feature
release: 0.2.0
targets:
- type: system
  id: target-selection
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
breaking: false
credit:
- ZivDero
- dkeeton
- AlexB
---

Outside a campaign, units choosing their own targets skip every object of a neutral house. `AttackNeutralUnits=Yes` in the `[Settings]` section of the client launch file, `SPAWN.INI`, now lets them choose those objects too.

In every game, campaigns included, a player's units choosing their own targets now also skip a structure whose weapon has no range, as they already skipped an unarmed one. Together with `AttackNeutralUnits`, this lets a player's units attack a neutral base's armed structures and leave its unarmed ones alone.

dkeeton is credited for the ts-patches patch this follows, and AlexB for the rule covering a structure whose weapon has no range.
