---
title: Correct the armor crate multiplier
category: fix
release: 0.1.0
breaking: true
migration:
- To preserve existing armor crate effects, replace each nonzero `Armor` row's third field in `[Powerups]` with its reciprocal. For example, change `Armor=33,ARMOR,0.5` to `Armor=33,ARMOR,2`.
- Replace a zero third field with a positive armor divisor; zero now causes division by zero during ordinary damage calculation.
targets:
- type: system
  id: crates
  effect: changed
credit: [ZivDero, Iran]
---

An armor crate now uses the `Armor` row's third field in `[Powerups]` as an armor divisor multiplier. A value of `2` halves ordinary incoming damage; `0.5` doubles it. Previously these effects were reversed.
