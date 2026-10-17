---
title: Allow ShakeScreen values below 2
category: fix
release: 0.2.0
targets:
- type: key
  id: ShakeScreen
  effect: changed
credit: [ZivDero, CCHyper]
---

`ShakeScreen=0` used to crash the game when a structure was destroyed, and values from `-1` through `1` crashed it when a vehicle with an explosion animation was destroyed. Those values are now safe.

CCHyper is credited for the Vinifera fix this follows.
