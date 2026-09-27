---
title: Hide player names in a quick match
category: feature
release: 0.2.0
targets:
- type: format
  id: spawn-ini
  effect: changed
- type: system
  id: chat
  effect: changed
- type: system
  id: multiplayer-score-screen
  effect: changed
credit:
- ZivDero
- dkeeton
---

`QuickMatch=yes` in the `[Settings]` section of `spawn.ini` shows the players as `Player 1` to `Player 8` wherever the match names them on screen, and each player has the same number on every machine. Their real names still appear in the launch file and the debug log.

A player name of 40 or more characters no longer overruns memory when the radar pane lists it.

dkeeton is credited for the ts-patches patch that first hid names in a quick match.
