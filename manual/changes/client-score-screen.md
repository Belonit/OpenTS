---
title: Pass over the score screen when a launch file asks
category: feature
release: 0.2.0
targets:
- type: format
  id: spawn-ini
  effect: changed
- type: system
  id: multiplayer-score-screen
  effect: added
credit:
- ZivDero
- Rampastring
- CCHyper
---

`SkipScoreScreen=yes` in `[Settings]` of `SPAWN.INI` skips the score screen at the end of a skirmish or network match. The ending movie still plays when `PlayMoviesInMultiplayer=yes` turns movies on. A map's `SkipScore` still affects only campaign missions.
