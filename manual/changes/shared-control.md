---
title: Let an ally command your units
category: feature
release: 0.2.0
targets:
- type: system
  id: shared-control
  effect: added
- type: command
  id: GrantControl
  effect: added
- type: format
  id: spawn-ini
  effect: changed
- type: system
  id: network-packet-validation
  effect: changed
credit:
- ZivDero
- dkeeton
---

With `SharedControl=yes` in the `[Settings]` section of `spawn.ini`, a player in a network game can select an ally's object and press `GrantControl` to let that ally select and order their units. Pressing it again takes the grant back, and it ends when the alliance breaks or either player is defeated or leaves. Production, selling, repairing and power stay with the owner.

dkeeton wrote shared control for ts-patches.
