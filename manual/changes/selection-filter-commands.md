---
title: Filter a mixed selection by rank or health, and drop one unit from it
category: feature
release: 0.2.0
targets:
- type: command
  id: VeterancyFilter
  effect: added
- type: command
  id: VeterancyFilterAddLower
  effect: added
- type: command
  id: HealthFilter
  effect: added
- type: command
  id: HealthFilterAddLower
  effect: added
- type: command
  id: SelectOneLess
  effect: added
credit: [ZivDero, hacklex, dkeeton]
---

`VeterancyFilter` narrows a mixed selection to its highest rank; each further press selects the next lower rank from the selection it started with, returning to the highest after the lowest. `HealthFilter` does the same with the red, yellow and green health bands, most damaged first. `VeterancyFilterAddLower` and `HealthFilterAddLower` add the next rank or band to a filtered selection instead of replacing it. Neither filter works while a structure is being placed.

`SelectOneLess` deselects the most recently selected unarmed object, such as a harvester. When every selected object is armed, it deselects the one selected first.

None of the five has a default key. Bind them in the keyboard options or under `[Hotkey]` in `KEYBOARD.INI`.

hacklex is credited for the Vinifera filters this follows and dkeeton for the ts-patches command that removes one unit.
