---
title: Send a harvester to work when it leaves a factory
category: feature
release: 0.2.0
targets:
- type: key
  id: Harvester
  scope: unittype
  effect: changed
- type: key
  id: Weeder
  scope: unittype
  effect: changed
- type: system
  id: tiberium
  effect: changed
- type: system
  id: veins
  effect: changed
credit: [ZivDero, AlexB]
---

A harvester or weeder leaving a war factory or a repair bay now starts harvesting instead of stopping on the exit cell. When the factory has a rally point, the harvester drives there first and looks for Tiberium from there.

An armed harvester or weeder with nothing to do now behaves as an unarmed one does. It used to guard like any armed vehicle. A computer player's harvester or weeder goes back to harvesting. A player's goes back to harvesting only when it stops on Tiberium, or on veins for a weeder, and guards anywhere else.
