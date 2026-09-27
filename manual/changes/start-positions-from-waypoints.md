---
title: Draw start positions from placed waypoints before open ground
category: fix
release: 0.2.0
targets:
- type: system
  id: starting-forces
  effect: changed
- type: key
  id: Official
  scope: scenarios-2
  effect: changed
credit:
- ZivDero
---

A house now starts on random open ground only after every eligible start waypoint, `0` through `7`, has been taken. An unofficial map used to be padded to eight positions with random open ground before the first house drew, so a house could start away from every placed waypoint while one was still free. Which waypoints `[Basic] Official=` makes eligible is unchanged.
