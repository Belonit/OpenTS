---
title: Watch a multiplayer match as an observer
category: feature
release: 0.2.0
targets:
- type: system
  id: observers
  effect: added
- type: format
  id: spawn-ini
  effect: changed
- type: format
  id: save-games
  effect: changed
- type: system
  id: map-visibility
  effect: changed
- type: system
  id: cloaking
  effect: changed
- type: system
  id: sidebar
  effect: changed
- type: system
  id: veterancy
  effect: changed
- type: system
  id: power
  effect: changed
- type: system
  id: ion-storms
  effect: changed
credit:
- ZivDero
- Iran
- dkeeton
---

A seat listed under `[IsSpectator]` in `spawn.ini` watches the match without playing. The observer's house starts defeated with nothing on the map, sees the whole map with the radar up, and sees every house's cloaked and underground objects, pips and rank insignia as their owners do. Its credit readout shows the match time, it can message only everyone or the other observers, and it is left out of the score screen, the radar pane's name list and the statistics report.

A defeated player now sees the whole map as an observer does. The fog is lifted and kept from growing back, and every house's cloaked and underground objects, pips and rank insignia are shown.

`CoachMode=yes` in the `[Settings]` section of `spawn.ini` lets a defeated player keep their allies' vision and private chat instead of seeing the whole map.

Iran wrote the spawner's observer seats, from the code he wrote for Red Alert. dkeeton added coach mode to ts-patches.
