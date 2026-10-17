---
title: Vehicle thieves are not offered allied vehicles
category: fix
release: 0.2.0
targets:
- type: key
  id: VehicleThief
  effect: changed
credit: [ZivDero, Rampastring]
---

A player's `VehicleThief=yes` soldier used to get the enter cursor over an allied player's vehicle, so a click ordered it to steal that vehicle. The cursor now appears only over vehicles whose owner is not allied with the soldier's house.

Rampastring is credited for the Vinifera fix this follows.
