---
title: Read alliances from the spawn house sections outside campaign
category: feature
release: 0.2.0
targets:
- type: key
  id: Allies
  effect: changed
- type: format
  id: scenario-objects
  effect: changed
credit:
- ZivDero
---

A skirmish or multiplayer map can now set `Allies=` in `[Spawn1]` through `[Spawn8]`, listing spawn houses or countries. The house at that start position begins the match allied to each listed spawn house and to every player of each listed country, in addition to the alliances the launch settings make. The alliance is one way: the listed houses are not allied back. A section for a position nobody holds is ignored.
