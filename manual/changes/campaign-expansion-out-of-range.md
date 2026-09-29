---
title: Hide campaigns whose expansion number matches no expansion
category: fix
release: 0.2.0
targets:
- type: key
  id: RequiredAddon
  scope: campaign
  effect: changed
credit:
- ZivDero
---

A campaign whose `RequiredAddon=` in its `BATTLE*.INI` section is not `-1`, `0` or `1` now never appears in the mission list. Some of those numbers, such as `32` and `33`, used to list the campaign while Firestorm was running.
