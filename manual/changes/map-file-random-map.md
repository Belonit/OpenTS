---
title: Build a random map when a map file asks for one
category: feature
release: 0.2.0
targets:
- type: key
  id: RandomMap
  effect: added
- type: format
  id: spawn-ini
  effect: changed
- type: system
  id: map-generation
  effect: changed
credit:
- ZivDero
- dkeeton
---

A scenario file with `RandomMap=yes` in `[Basic]` is now generated as a random map from its `[RandomMap]` section, as a `.SED` seed file is. The match's seed drives the generator, so every machine builds the same map and each new seed builds a different one. The file's other settings still apply, such as its rules sections and `FreeRadar`, but the generator sets the map's size, theater and lighting, `Player` in `[Basic]`, and `TechLevel` in the first country's section.

dkeeton is credited for the ts-patches patch that first let a map file ask for a random map.
