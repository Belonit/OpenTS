---
title: Honor a trigger's difficulty flags
category: fix
release: 0.1.0
breaking: true
migration:
- In map trigger records, set each difficulty field to `1` where the trigger should remain active. A field set to `0` now disables it at that difficulty.
targets:
- type: action
  id: TACTION_ENABLE_TRIGGER
  effect: changed
credit: [ZivDero, tomsons26]
---

A trigger's three difficulty fields now disable it at difficulties set to `0`; previously all triggers ran at every difficulty. Enable Trigger cannot enable a trigger excluded by the difficulty. Campaigns use the chosen mission difficulty, while skirmish and network games use the lobby's computer skill.
