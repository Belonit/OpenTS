---
title: Recover from an out-of-sync game with a dialog and an in-game multiplayer load
category: feature
release: 0.2.0
breaking: true
migration:
- Tools that waited for `SAVEGAME.NET` to appear must list `SVGM_nnn.NET` instead; the CnCNet client already does.
targets:
- type: system
  id: out-of-sync-recovery
  effect: added
- type: format
  id: save-games
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
- type: system
  id: network-packet-validation
  effect: changed
credit:
- ZivDero
- Rampastring
---

A network game that went out of sync used to show a two-button box whose Continue dropped every connection. It now halts and opens a dialog in which the master loads one of the match's saved games, continues, or quits. Everyone else waits with a player list and a chat box and can quit after ten seconds. Continue now makes each machine drop only the players out of sync with it.

The master can also load one of the match's saves from the options menu during play. `Host=yes` in the `[Settings]` section of `spawn.ini` makes that machine the master after such a load. Before any load, and in a match without it, the lowest seat is the master.

Every network game now numbers its saves `SVGM_000.NET` upward, and a new match deletes the previous match's numbered saves. A match started from `spawn.ini` copies that file to `spawnSG.ini` at its first save. `SAVEGAME.NET` is no longer written.

The dialog and the in-game load follow Vinifera's, by ZivDero and Rampastring.
