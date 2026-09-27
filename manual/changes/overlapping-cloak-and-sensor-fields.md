---
title: Count overlapping cloak and sensor fields
category: fix
release: 0.2.0
targets:
- type: system
  id: cloaking
  effect: changed
- type: key
  id: SensorArray
  effect: changed
- type: key
  id: CloakGenerator
  effect: changed
credit: [ZivDero]
---

A cell covered by two cloak generators or two sensor arrays of one house now stays covered as long as one of them still covers it. Before, when one generator's field collapsed, the shared cells lost their cloak until the other generator's field grew back over them. When one array was taken off the map, the shared cells stayed sensed only if the other array was operational at that moment.

Capturing a sensor array now removes its coverage from the old owner and, if the array is operational at that moment, gives it to the new owner. Before, the old owner kept sensing the array's cells for the rest of the game, and the new owner sensed nothing until a cloak field finished growing or another array was removed.
