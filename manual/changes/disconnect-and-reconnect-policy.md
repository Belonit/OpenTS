---
title: Decide what happens when a player leaves a match
category: feature
release: 0.2.0
targets:
- type: system
  id: leaving-a-match
  effect: added
- type: system
  id: reconnect-dialog
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
breaking: true
migration:
- A client or mod that wants a departed player's base handed to the computer must write `AutoSurrender=No` in the launch file. Without it a client-launched match now destroys the base.
credit:
- ZivDero
- Rampastring
---

A player who leaves a client-launched match now has their base destroyed, unless the launch file writes `AutoSurrender=No` in `[Settings]` of `SPAWN.INI`, which hands the base to the computer instead. A player who leaves a match started from the game's own menu still has their base handed to the computer. A seat the computer takes over now keeps the player's name, so the radar list, chat and the score screen still show who held it.

`ConnTimeout` and `ReconnectTimeout` in the same section set how long this machine waits before dropping another machine. `ConnTimeout` applies to one that stops making progress on the loading screen, and `ReconnectTimeout` to one that goes quiet during play. A larger value waits longer, and each machine applies its own values.

Closing the window or pressing Alt+F4 during a match now resigns, as Abort in the options menu does; it used to be ignored.

The launch file's `ContinueWithoutHumans` is not read. A match ends once no person is left playing it. A match seated only by observers continues until one side remains.
