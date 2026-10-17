---
title: Stop aircraft unloading crashing outside a team
category: fix
release: 0.2.0
targets:
- type: system
  id: transports
  effect: changed
credit: [ZivDero, CCHyper]
---

An aircraft transport that belongs to no team no longer crashes the game when a passenger that belongs to a team leaves it. The passenger keeps its own team. When the aircraft has a team, the passenger still joins it.

CCHyper is credited for the Vinifera fix this follows.
