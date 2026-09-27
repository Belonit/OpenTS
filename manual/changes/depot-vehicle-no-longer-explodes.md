---
title: Stop vehicles blowing up on a service depot pad
category: fix
release: 0.2.0
targets:
- type: system
  id: repair
  effect: changed
- type: key
  id: C4Warhead
  effect: changed
credit: [ZivDero, dkeeton]
---

A vehicle that is stopped or given another order while it drives onto a service depot's pad now moves off the pad. It used to be destroyed as soon as it reached the pad cell. The same applies to a vehicle that ends a move on any structure's cell it may not stand on. A vehicle stopped on terrain it cannot enter is still destroyed.

dkeeton is credited for the ts-patches change this follows.
