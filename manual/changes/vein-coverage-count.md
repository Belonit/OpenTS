---
title: Count each mature vein cell once toward a veinhole's limit
category: fix
release: 0.2.0
targets:
- type: system
  id: veins
  effect: changed
- type: key
  id: MaxVeinholeGrowth
  effect: changed
credit:
- ZivDero
---

A veinhole monster stops growing once it covers more than `MaxVeinholeGrowth` minus 100 mature vein cells; `MaxVeinholeGrowth` is set in `[General]` of `rules.ini`, and a higher value lets the field grow larger. When a scenario loaded, each mature cell the map placed in the monster's field counted twice and each thin cell once, so with the shipped rules a field of more than about 950 mature cells could not grow. Each mature cell now counts once, thin cells do not count, and a cell that fails to mature during growth no longer counts.
