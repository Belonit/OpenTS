---
title: Aim an anti-air defense at a chosen aircraft
category: balance
release: 0.2.0
targets:
- type: key
  id: SAM
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
breaking: false
credit:
- ZivDero
- dkeeton
---

A defense whose weapon can hit only targets in the air used to refuse attack orders and choose its own targets. It now accepts an attack order against an aircraft in flight within its range and fires at that aircraft. The attack cursor appears only over targets the weapon can hit, so a landed aircraft, a ground unit or open ground shows none. `AimableSams` in the client launch file, `SPAWN.INI`, is not read, because OpenTS allows the order without it.

dkeeton is credited for the ts-patches patch this follows, which enabled the order through `AimableSams`.
