---
title: Hold a seed file's settings in range when it is played
category: fix
release: 0.2.0
targets:
- type: format
  id: map-seed
  effect: changed
- type: system
  id: map-generation
  effect: changed
credit:
- ZivDero
---

When a seed file, or a map file with `RandomMap=yes` in `[Basic]`, is played, each `[RandomMap]` setting is now held to the range the random map dialog allows, and a setting the file leaves out takes its default. In a seed file, an out-of-range value such as `NumPlayers=9` used to read past the end of the generator's tables, and a `RegionSize` below `-10` hung the game. A missing setting kept its value from the last map generated, so two machines could build different maps.

`Seed=-1` in a seed file now becomes `0`, so the file builds the map that seed `0` gives.
