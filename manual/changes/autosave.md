---
title: Save the game automatically at a fixed interval
category: feature
release: 0.2.0
targets:
- type: key
  id: AutoSaveInterval
  effect: added
- type: format
  id: save-games
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
credit:
- ZivDero
- Rampastring
---

The game now saves automatically each time a set number of game frames has passed. A campaign mission rotates through `AUTOSAVE1.SAV` to `AUTOSAVE5.SAV`, and a skirmish through `AUTOSAVE_SKIRMISH1.SAV` to `AUTOSAVE_SKIRMISH5.SAV`. For a campaign or skirmish started from the menu, the new `AutoSaveInterval` under `[Options]` in `sun.ini` sets that number of frames; a larger value saves less often. A network game started from the menu does not save automatically.

A game started by a client takes its interval from `AutoSaveGame` in the `[Settings]` section of the client launch file, `SPAWN.INI`. In such a game against other players, every machine writes a numbered multiplayer save at the same frame. `NextSPAutoSaveId` and `NextSkirmishAutoSaveId` in the same section choose the first campaign and skirmish autosave file to write.

Every save records which autosave file comes next, so a loaded game continues the rotation.
