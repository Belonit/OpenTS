---
title: Carry the scenario file in the save game
category: feature
release: 0.2.0
targets:
- type: format
  id: save-games
  effect: changed
- type: system
  id: campaign-progression
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
- type: format
  id: opents-ini
  effect: changed
credit:
- ZivDero
---

`CarryScenarioFile=yes` in `[Saves]` of the deployment's `OPENTS.INI` stores a copy of the scenario file in each save. Restarting the mission, or replaying it after a loss, then reads the mission from that copy instead of the file on disk. A mission resumed through the CnCNet client can then be restarted, because the restart no longer reads the stub `spawnmap.ini` the client writes when it resumes a game.
