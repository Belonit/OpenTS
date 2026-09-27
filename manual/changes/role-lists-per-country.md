---
title: Resolve every role list against the country a house acts as
category: fix
release: 0.2.0
targets:
- type: key
  id: ActsLike
  effect: changed
- type: key
  id: HarvesterUnit
  effect: changed
- type: key
  id: BuildRefinery
  effect: changed
- type: key
  id: BuildWeapons
  effect: changed
- type: key
  id: BuildPower
  effect: changed
- type: key
  id: BuildBarracks
  effect: changed
- type: key
  id: BuildRadar
  effect: changed
- type: key
  id: BuildTech
  effect: changed
- type: key
  id: ConcreteWalls
  effect: changed
- type: key
  id: EWGates
  effect: changed
- type: key
  id: NSGates
  effect: changed
- type: system
  id: ai-base-building
  effect: changed
credit: [ZivDero, AlexB]
---

The lists that name which type fills a role now pick the first type that the country named by `ActsLike=` in the house's section of the scenario file may own. `ActsLike=` makes a house build and plan as that country. The lists include `BuildRefinery`, `BuildPower` and `ConcreteWalls` in `[AI]` of `rules.ini` and `HarvesterUnit` in `[General]`; `HarvesterUnit` takes its first entry when the country may own none of its entries. The lists used to pick for the house's own country, while its construction yard could build only what the `ActsLike` country may own. A campaign house acting as another country could therefore plan a base out of structures it could never build.

AlexB is credited for the ts-patches bundle, which resolves its picks the same way.
