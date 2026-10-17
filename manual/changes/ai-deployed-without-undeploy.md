---
title: Computer houses keep deployed structures that cannot pack up
category: fix
release: 0.2.0
targets:
- type: key
  id: TickTank
  effect: changed
- type: key
  id: Artillary
  effect: changed
- type: key
  id: IsJuggernaut
  effect: changed
credit: [ZivDero, Rampastring]
---

A computer-owned `TickTank=yes`, `Artillary=yes` or `IsJuggernaut=yes` structure without an `UndeploysInto=` vehicle used to sell itself when it was given a target beyond its range. It now stays deployed. One with an `UndeploysInto=` vehicle still packs up.

Rampastring is credited for the Vinifera fix this follows.
