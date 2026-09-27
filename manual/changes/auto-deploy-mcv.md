---
title: Deploy the starting MCV on AutoDeployMCV
category: feature
release: 0.2.0
targets:
- type: system
  id: starting-forces
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
breaking: false
credit:
- ZivDero
- Rampastring
- CCHyper
- tomsons26
---

In a match with bases on, `AutoDeployMCV=Yes` in the `[Settings]` section of the client launch file, `SPAWN.INI`, makes every house's starting base unit deploy as the match begins, computer houses included. Play then starts with construction yards. A base unit whose ground cannot take its structure stays a vehicle.

Rampastring is credited for the ts-patches patch this follows, and CCHyper and tomsons26 for the Vinifera option.
