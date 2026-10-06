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
- type: key
  id: ArmorCrateStacksAdditively
  effect: added
- type: key
  id: FirepowerCrateStacksAdditively
  effect: added
- type: system
  id: crates
  effect: changed
credit: [ZivDero, dkeeton]
---

`ArmorCrateStacks` and `FirepowerCrateStacks` in `[CrateRules]` of `rules.ini` let armor and firepower crates upgrade objects again at `yes`. `ArmorCrateStacksAdditively` and `FirepowerCrateStacksAdditively` in the same section make each upgrade add the corresponding `[Powerups]` entry's third field to the current multiplier at `yes`, including on the first pickup. With the additive settings disabled, each upgrade multiplies by that field.

dkeeton is credited for the ts-patches crate patch that first let armor crates stack.
