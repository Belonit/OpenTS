---
title: Let a building be placed over an overlay
category: feature
release: 0.2.0
targets:
- type: key
  id: BuildableOver
  effect: added
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, Rampastring]
---

`BuildableOver=yes` in an overlay type's `rules.ini` section lets a structure be placed on cells that hold that overlay, by the player or by a computer house. The cell's land type must still allow building, and `BuildableOver` has no effect on a wall overlay.
