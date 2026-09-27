---
title: Draw the whole queued route and both order lines, styled by UI.INI
category: feature
release: 0.2.0
targets:
- type: format
  id: ui-ini
  effect: added
- type: system
  id: action-lines
  effect: added
- type: key
  id: UnitActionLines
  effect: changed
- type: key
  id: AlwaysShowActionLines
  effect: added
- type: key
  id: MovementLineDashed
  effect: added
- type: key
  id: MovementLineDropShadow
  effect: added
- type: key
  id: MovementLineThick
  effect: added
- type: key
  id: MovementLineColor
  effect: added
- type: key
  id: MovementLineDropShadowColor
  effect: added
- type: key
  id: TargetLineDashed
  effect: added
- type: key
  id: TargetLineDropShadow
  effect: added
- type: key
  id: TargetLineThick
  effect: added
- type: key
  id: TargetLineColor
  effect: added
- type: key
  id: TargetLineDropShadowColor
  effect: added
- type: key
  id: TargetLaserDashed
  effect: added
- type: key
  id: TargetLaserDropShadow
  effect: added
- type: key
  id: TargetLaserThick
  effect: added
- type: key
  id: TargetLaserColor
  effect: added
- type: key
  id: TargetLaserDropShadowColor
  effect: added
- type: key
  id: TargetLaserTime
  effect: added
- type: key
  id: ShowNavComQueueLines
  effect: added
- type: key
  id: NavComQueueLineDashed
  effect: added
- type: key
  id: NavComQueueLineDropShadow
  effect: added
- type: key
  id: NavComQueueLineThick
  effect: added
- type: key
  id: NavComQueueLineColor
  effect: added
- type: key
  id: NavComQueueLineDropShadowColor
  effect: added
credit: [ZivDero, CCHyper, tomsons26]
---

A selected object drew either its target line or its movement line, never both, and showed none of its queued destinations. Both lines now draw together, and destinations queued with the queue-move key continue from the end of the movement line as further lines. A looping queue closes into a ring.

The lines now also show while the queue-move key is held. The new optional file `UI.INI` controls them from its `[Ingame]` section. `AlwaysShowActionLines=yes` keeps them shown for as long as the object is selected, provided `UnitActionLines` under `[Options]` in `sun.ini` is on. `ShowNavComQueueLines=no` hides the queue lines.

The same section sets the color, dashes, thickness and drop shadow of each line. Its `TargetLaser` keys style the sighting laser drawn by a vehicle with `TargetLaser=yes` in its `rules.ini` section, and `TargetLaserTime` sets how long that laser stays after each shot. Without `UI.INI`, the target and movement lines look as they did before.

The keys are named as in Vinifera's `UI.INI`, so the action line settings of a file written for Vinifera carry over. CCHyper and tomsons26 are credited for that implementation.
