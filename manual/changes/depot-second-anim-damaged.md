---
title: Damaged service depots use damaged art for the second repair stage
category: fix
release: 0.2.0
targets:
- type: key
  id: SpecialAnimTwoDamaged
  effect: changed
credit: [ZivDero]
---

A service depot at or below `ConditionYellow` used to start the second stage of its repair animation with the healthy `SpecialAnimTwo=` art. It now starts with `SpecialAnimTwoDamaged=`, which falls back to `SpecialAnimTwo=` when it is not set.
