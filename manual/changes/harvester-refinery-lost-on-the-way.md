---
title: Keep harvesting when a refinery is lost on the way in
category: fix
release: 0.2.0
targets:
- type: system
  id: tiberium
  effect: changed
- type: system
  id: veins
  effect: changed
credit: [ZivDero, Rampastring]
---

A player's harvester or weeder heading for a refinery that is destroyed, sold or captured before it docks now goes back to harvesting. A full one looks for another refinery. It used to stop and stand guard unless it happened to be on Tiberium or veins, while a computer player's harvester already went back to work.

Rampastring is credited for the ts-patches change this follows.
