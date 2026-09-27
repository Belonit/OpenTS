---
title: Name a harvester's unloading artwork per type
category: feature
release: 0.2.0
targets:
- type: key
  id: UnloadingClass
  effect: added
- type: key
  id: UnloadingHarvester
  effect: changed
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, CCHyper]
---

`UnloadingClass=` in a harvester type's section of `rules.ini` names the vehicle drawn in its place while it unloads at a refinery, and overrides `UnloadingHarvester=` for that type. Every Tiberium harvester used to be drawn as the one vehicle `UnloadingHarvester=` in `[AudioVisual]` names. A `Weeder=yes` vein harvester, which `UnloadingHarvester=` never applied to, can use `UnloadingClass=` too.
