---
title: Pick the nearest docking bay on a large map
category: fix
release: 0.2.0
targets:
- type: key
  id: Dock
  effect: changed
- type: system
  id: tiberium
  effect: changed
credit: [ZivDero]
---

A harvester or aircraft more than about 181 cells from a building it can dock with now picks the nearest one, as it does at shorter range. The distance used to overflow at that range, so on a large map a harvester could drive to a farther refinery and an aircraft fly to a farther pad.
