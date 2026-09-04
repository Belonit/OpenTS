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

A selected object now draws its target line and its movement line together rather than one or the other, the movement line reaches the far end of the planned route, and the destinations queued with the queue-move key continue from it as further lines, closing into a ring for a looping queue. The lines also show while that key is held. `UI.INI`, a new optional file, sets each line's colour, dashes, thickness and shadow, keeps the lines on with `AlwaysShowActionLines=yes`, and styles and times the `TargetLaser=` sighting line the same way. Without the file the lines look as before, apart from both drawing together and the queue being shown.

The keys and their names follow Vinifera's `UI.INI`, so a file written for it carries over. CCHyper and tomsons26 are credited for that implementation.
