---
title: Set a rally point with a plain click
category: feature
release: 0.2.0
breaking: true
migration:
- Set `AltToRally=yes` under `[Options]` in `sun.ini` to keep the old rally-point and mobile-factory controls.
targets:
- type: key
  id: AltToRally
  effect: added
- type: key
  id: IsMobileWar
  effect: changed
- type: system
  id: production
  effect: changed
credit: [ZivDero, AlexB]
---

A plain click on the ground with a vehicle, infantry or aircraft factory selected now sets its rally point, where it used to do nothing. The force-move key, which used to set the rally point, now does nothing on a factory that cannot pack up.

On a factory that can pack up, such as Firestorm's mobile war factory, the plain click used to pack it up and now sets the rally point. The force-move key packs it up instead.

`AltToRally=yes` under `[Options]` in `sun.ini` restores the old controls for the player who sets it.

AlexB is credited for the ts-patches option this follows.
