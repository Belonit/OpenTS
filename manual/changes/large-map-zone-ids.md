---
title: Carry zone and subzone ids on large maps
category: fix
release: 0.2.0
targets:
- type: system
  id: route-search
  effect: changed
- type: format
  id: save-games
  effect: changed
credit: [ZivDero]
---

Route search no longer reads or writes outside its tables, which could corrupt memory or crash the game. A map with more than 32767 subzones, the blocks of connected cells the route search plans across, no longer produces negative table positions. A terrain change near the bottom or right edge of the playfield no longer writes past the end of the zone tables. A route longer than 2000 cells is no longer built; it used to be written past the end of the unit's move list.
