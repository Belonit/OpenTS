---
title: Enable Trigger leaves an enabled trigger's countdown running
category: fix
release: 0.2.0
breaking: true
migration:
- To restart the countdown of a trigger that is already enabled, run Disable Trigger on it before Enable Trigger.
targets:
- type: action
  id: TACTION_ENABLE_TRIGGER
  effect: changed
credit: [ZivDero, Rampastring]
---

Enable Trigger used to restart the elapsed time and random delay countdown of a trigger that was already enabled. It now enables only disabled triggers, so a countdown in progress keeps running.

Rampastring is credited for the Vinifera fix this follows.
