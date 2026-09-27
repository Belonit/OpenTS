---
title: Refuse a scenario whose terrain data is damaged
category: fix
release: 0.2.0
targets:
- type: format
  id: scenario-terrain
  effect: changed
credit:
- gunnarbeutner
---

A scenario whose `[IsoMapPack4]` or `[IsoMapPack5]` section is damaged used to start with the terrain of every cell after the damage missing. It now fails to load with a message that its map data is damaged, and the debug log names the section. A section is damaged when a block does not decompress to the size its header states, or when the cell records end before their 0,0 terminator.
