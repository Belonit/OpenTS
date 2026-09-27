---
title: Let a structure produce cash on an interval
category: feature
release: 0.2.0
targets:
- type: key
  id: ProduceCashStartup
  effect: added
- type: key
  id: ProduceCashStartupOneTime
  effect: added
- type: key
  id: ProduceCashAmount
  effect: added
- type: key
  id: ProduceCashDelay
  effect: added
- type: key
  id: ProduceCashBudget
  effect: added
- type: key
  id: ProduceCashResetOnCapture
  effect: added
- type: system
  id: produce-cash
  effect: added
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, CCHyper, Rampastring]
---

Six keys in a structure type's `rules.ini` section make the structure pay or charge its owner. `ProduceCashAmount=` gives the owner that many credits every `ProduceCashDelay=` frames, and a negative amount is taken from the owner instead. `ProduceCashBudget=` caps the total one structure pays or charges, and `ProduceCashResetOnCapture=yes` restores the full budget for each new owner. A structure whose owner's country has `MultiplayPassive=yes` pays and charges nothing.

`ProduceCashStartup=` pays a bonus to each house that captures the structure from a house whose country has `MultiplayPassive=yes`. `ProduceCashStartupOneTime=yes` pays that bonus only on the structure's first such capture.

A `Powered=yes` structure pauses its interval while it is switched off, stunned by an EM pulse, or its owner is short of power, and resumes with the frames it had left.
