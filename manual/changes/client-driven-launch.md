---
title: Launch and play a game from a client's launch file
category: feature
release: 0.2.0
targets:
- type: command
  id: launch:spawn
  effect: added
- type: format
  id: spawn-ini
  effect: added
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, Rampastring, dkeeton, FunkyFr3sh, CCHyper, Belonit, hifi, Iran]
---

Starting the game with `-SPAWN` now plays the match `SPAWN.INI` describes: a skirmish, a campaign mission, or a game against other machines, played through a CnCNet tunnel or directly between them. Any of these can also resume a saved game. The game skips the startup movies and the menu, and exits when the match ends.

The people credited here wrote the earlier spawners this one follows.
