---
title: Count every listed refinery and harvester
category: fix
release: 0.2.0
targets:
- type: key
  id: HarvesterUnit
  effect: changed
- type: key
  id: BuildRefinery
  effect: changed
- type: key
  id: BuildWeapons
  effect: changed
credit: [ZivDero, AlexB]
---

When a computer house checks whether it can keep earning money, it now counts every refinery in `BuildRefinery` under `[AI]` and every harvester in `HarvesterUnit` under `[General]` of `rules.ini`. It used to count only the first entry of each. A house whose refinery or harvester was a later entry used to sell its base to replace what it already had, and never ordered a replacement harvester.

To price or order a refinery or a harvester, the house now takes the first entry its country may own, or the first entry when it may own none. It picks the `BuildWeapons` factory under `[AI]` to price for building a harvester the same way.

Harvesters now spread out across a Tiberium field according to how many harvesters of every `HarvesterUnit` entry their house owns. Only the first entry used to be counted, so a house whose harvesters were a later entry spread them out as if it had one.

An empty `BuildRefinery` or `HarvesterUnit` list no longer crashes the game.

AlexB is credited for the ts-patches bundle that first read these lists whole.
