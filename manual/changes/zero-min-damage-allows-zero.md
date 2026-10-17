---
title: MinDamage=0 lets armor reduce a hit to nothing
category: fix
release: 0.2.0
targets:
- type: key
  id: MinDamage
  effect: changed
- type: key
  id: Verses
  effect: changed
credit: [ZivDero]
---

A hit that a warhead's `Verses=` entry reduced to zero used to become one point, so a `0%` entry still damaged nearby targets even with `MinDamage=0`. With `MinDamage=0` or less, that hit now stays at zero. With a positive `MinDamage`, damage is unchanged.
