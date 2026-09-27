---
title: Give each country its own base unit
category: feature
release: 0.2.0
targets:
- type: key
  id: BaseUnit
  effect: changed
- type: system
  id: starting-forces
  effect: changed
credit: [ZivDero, CCHyper]
---

`BaseUnit=` under `[General]` in `rules.ini` now takes a list of vehicle types, so each country can start with its own MCV. A house starts with the first listed type whose `Owner=` includes its country, or with the first entry when none does. Every house used to start with the same base unit, whatever country it played.

A single value, as before, gives every house that unit. An empty list, which used to crash the game before the match started, now starts every house without a base unit.

CCHyper is credited for Vinifera's list under the same key, which this follows.
