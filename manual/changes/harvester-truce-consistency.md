---
title: Hold the harvester truce to one list
category: fix
release: 0.2.0
targets:
- type: key
  id: HarvesterUnit
  effect: changed
- type: key
  id: HarvesterImmune
  effect: changed
credit: [ZivDero, AlexB]
---

Under the harvester truce, outside a short game, a multiplayer house that has lost its structures, infantry and aircraft is now defeated when its only remaining vehicles are harvesters. Every type in the `HarvesterUnit` list, under `[General]` in `rules.ini`, counts as a harvester here. Only the first entry used to count, so a house left with harvesters of a later type stayed in the game. In such a game the truce is the harvester truce option: `HarvesterTruce` in the `[Settings]` section of the client launch file, `SPAWN.INI`, or the truce check box in the network lobby. It protects harvesters of those types from attack.

Under the truce, a vehicle thief ordered onto a protected harvester now selects it. It used to capture it. This also holds in a mission that sets `HarvesterImmune=yes` under `[SpecialFlags]` in the map file.

AlexB is credited for the ts-patches bundle that first read this list whole.
