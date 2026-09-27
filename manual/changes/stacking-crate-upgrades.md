---
title: Let armor and firepower crates stack
category: feature
release: 0.2.0
targets:
- type: key
  id: ArmorCrateStacks
  effect: added
- type: key
  id: FirepowerCrateStacks
  effect: added
- type: system
  id: crates
  effect: changed
credit: [ZivDero, dkeeton]
---

`ArmorCrateStacks` and `FirepowerCrateStacks` in `[CrateRules]` of `rules.ini` let armor and firepower crates stack. At `yes`, a crate of that kind also upgrades objects that already have the upgrade and multiplies their armor or firepower multiplier again each time. A collector that already has the upgrade then gets it again instead of money. At `no`, each object takes that upgrade only once.

dkeeton is credited for the ts-patches crate patch that first let armor crates stack.
