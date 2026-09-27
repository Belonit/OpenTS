---
title: Guard sends harvesters to work and holds other units where they stand
category: feature
release: 0.2.0
targets:
- type: command
  id: GuardObject
  effect: changed
credit: [ZivDero, AlexB, dkeeton, CCHyper]
---

The Guard command now sends a selected harvester or weeder back to harvesting, unless it is unloading. An unarmed harvester used to ignore the key, and an armed one guarded like any other armed unit.

Every other selected object that can move and fire now guards the area around the spot where it stands when the key is pressed. It used to guard around the cell it was heading for, so a moving unit finished its trip before guarding.

AlexB and CCHyper are credited for the harvester behavior in ts-patches and Vinifera, and dkeeton for the ts-patches change that holds units in place.
