---
title: Declare extra theaters in the rules
category: feature
release: 0.2.0
targets:
- type: format
  id: rules-registries
  effect: changed
- type: format
  id: theater-control
  effect: changed
- type: key
  id: Root
  effect: added
- type: key
  id: IsoRoot
  effect: added
- type: key
  id: Suffix
  scope: theater
  effect: added
- type: key
  id: MMSuffix
  effect: added
- type: key
  id: ImageLetter
  effect: added
- type: key
  id: IsArctic
  effect: added
- type: key
  id: IsIceGrowthEnabled
  effect: added
- type: key
  id: LowRadarBrightness
  effect: added
- type: key
  id: HighRadarBrightness
  effect: added
- type: key
  id: Theater
  scope: scenarios
  effect: changed
- type: key
  id: NewTheater
  effect: changed
credit: [ZivDero]
---

`[Theaters]` lists in `rules.ini` and, when Firestorm is installed, in `firestrm.ini` now declare the theaters a game has. The theaters `rules.ini` lists come first, followed by any new names `firestrm.ini` lists. A list in either file replaces the built-in `TEMPERATE` and `SNOW`, so a mod may drop, reorder or replace them and must list any it keeps. Rules with no list in either file keep those two.

Each theater's archive names, artwork extensions, image letter, arctic terrain, ice growth and radar brightness come from a section named after the theater. That section is read from `rules.ini` and then, when Firestorm is installed, from `firestrm.ini`, so a value set in `firestrm.ini` wins.

A `NewTheater=yes` type's image in `art.ini`, and a structure's artwork, is now renamed when the second letter of its name is any declared theater's image letter. That letter is replaced by the current theater's image letter. Only names starting `GA`, `NA`, `GT`, `NT`, `CA` or `CT` were renamed before. In a new game the shipped artwork gets the same names as before, and a mod's artwork names now follow the theater.

A map whose `Theater=` names no declared theater is now played in the first declared theater. It used to load archives under whatever names lay in memory before the theater table.
