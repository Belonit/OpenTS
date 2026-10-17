---
title: Treat a negative sight range as no sight
category: fix
release: 0.2.0
targets:
- type: key
  id: AttackingAircraftSightRange
  effect: changed
- type: system
  id: map-visibility
  effect: changed
credit: [ZivDero, Rampastring]
---

A negative sight range, such as a negative `AttackingAircraftSightRange=`, used to read past the game's sight tables and could reveal an arbitrary area or crash the game. A sight range of zero or less now reveals nothing.

Rampastring is credited for the Vinifera fix this follows.
