---
title: Let the queue fill a positive build limit
category: fix
release: 0.2.0
targets:
- type: system
  id: production
  effect: changed
- type: key
  id: BuildLimit
  effect: changed
credit: [ZivDero, Rampastring]
---

A player can now queue a vehicle, infantry or aircraft type up to its positive `BuildLimit` while one of that type is in production. A positive `BuildLimit` in the type's `rules.ini` section caps how many of the type a house can own and have queued at once. The queue used to refuse an order one object early: with `BuildLimit=3`, none on the map and one in production, only one more could be queued; now two can.

Rampastring is credited for the ts-patches fix this follows.
