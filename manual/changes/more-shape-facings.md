---
title: Draw shape vehicles cut into more than eight facings
category: feature
release: 0.2.0
targets:
- type: key
  id: Facings
  effect: changed
- type: key
  id: TurretFacings
  effect: added
- type: key
  id: StartTurretFrame
  effect: added
- type: key
  id: Anim
  effect: changed
credit: [ZivDero, CCHyper]
---

A shape-drawn vehicle whose `art.ini` section sets `Facings` to `16`, `32` or `64` is now drawn at the facing it points; it used to be drawn with its first facing whatever way it pointed. `Facings=8` draws exactly as before, and any other count still draws the first facing.

A weapon's `Anim` list in `rules.ini` likewise now picks its entry by firing direction when it holds 16, 32 or 64 entries, as it already did for 8.

A turret's facing count now comes from the new `TurretFacings`, and the frame where its strip starts from the new `StartTurretFrame`, both in the vehicle's `art.ini` section. Their defaults reproduce the old turret drawing, so existing artwork is unchanged.
