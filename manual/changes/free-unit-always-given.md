---
title: Always give a structure's free unit
category: fix
release: 0.2.0
targets:
- type: key
  id: FreeUnit
  effect: changed
credit: [ZivDero, dkeeton]
---

A structure with a `FreeUnit=` now gives its unit to every owner when its buildup finishes. A human owner used to receive it only when the price paid exceeded the structure's `Cost=` minus the unit's, so a low enough price multiplier withheld it.

dkeeton is credited for the ts-patches change this follows.
