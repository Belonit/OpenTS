---
title: Build next to a mutually allied base
category: feature
release: 0.2.0
targets:
- type: system
  id: base-adjacency
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
- type: key
  id: BuildOffAllyAnyStructure
  effect: added
breaking: false
credit:
- ZivDero
- Iran
- AlexB
- CCHyper
- tomsons26
---

`BuildOffAlly=Yes` in the `[Settings]` section of the client launch file, `SPAWN.INI`, lets the player place a structure next to the buildings of an allied house as well as their own. Each house must have allied with the other, and the ally's building must still have `BaseNormal=yes`. When the player places a wall, cells the ally owns, such as its walls and bibs, do not count. The setting does not change where computer houses build.

`BuildOffAllyAnyStructure=no` under `[MultiplayerDefaults]` in `rules.ini` narrows this to the ally's construction yards.

Iran is credited for the CnCNet spawner feature this follows, AlexB for the ts-patches patch that corrected it, and CCHyper and tomsons26 for the Vinifera version.
