---
title: Read base building from the side a house acts as
category: feature
release: 0.2.0
targets:
- type: key
  id: RegularPowerPlant
  effect: added
- type: key
  id: AdvancedPowerPlant
  effect: added
- type: key
  id: PowerTurbine
  effect: added
- type: key
  id: HunterSeeker
  scope: side
  effect: added
- type: key
  id: AIWallTowers
  effect: added
- type: key
  id: AIBaseDefenseCoefficient
  effect: added
- type: key
  id: AIWallDefense
  effect: added
- type: key
  id: AIWallDefenseCoefficient
  effect: added
- type: key
  id: AIBuildsWalls
  scope: side
  effect: added
- type: key
  id: AIBaseDefensePlaceholders
  effect: added
- type: key
  id: AIBaseDefensesWithWalls
  effect: added
- type: key
  id: GDIHunterSeeker
  effect: changed
- type: key
  id: NodHunterSeeker
  effect: changed
- type: key
  id: GDIPowerPlant
  effect: changed
- type: key
  id: GDIPowerTurbine
  effect: changed
- type: key
  id: NodRegularPower
  effect: changed
- type: key
  id: NodAdvancedPower
  effect: changed
- type: key
  id: WallTower
  effect: changed
- type: key
  id: GDIBaseDefenseCoefficient
  effect: changed
- type: key
  id: NodBaseDefenseCoefficient
  effect: changed
- type: key
  id: GDIWallDefense
  effect: changed
- type: key
  id: GDIWallDefenseCoefficient
  effect: changed
- type: key
  id: NodAIBuildsWalls
  effect: changed
- type: system
  id: ai-base-building
  effect: changed
- type: system
  id: superweapons
  effect: changed
credit: [ZivDero, CCHyper, tomsons26]
---

A computer house now builds its base from the settings of the side it acts as. Each side sets them in the `rules.ini` section named after it. They cover its power plants and turbine, its hunter-seeker, the towers it places along its walls, how many base defenses and wall towers it plans, and whether it builds walls.

When a house runs short of power, it may first add the side's turbine to a regular plant it owns that has a free upgrade slot. Otherwise it builds the side's advanced plant once it owns that plant's prerequisites, and failing that the side's regular plant. A house whose side names no regular plant builds the first `BuildPower` entry its country can own instead.

A house on a side other than GDI or Nod used to take GDI's base-defense coefficient, build no wall towers, and answer a power shortage with Nod's power plants.

The first two sides in `[Sides]` still take the old `GDI` and `Nod` keys under `[General]` and `[AI]` from each file that sets them, so the shipped rules build the same bases as before.

CCHyper and tomsons26 are credited for Vinifera's side sections, whose power plant, turbine and hunter-seeker keys these share.
