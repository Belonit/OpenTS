---
title: Write an out-of-sync report with bounded histories
category: feature
release: 0.2.0
targets:
- type: system
  id: developer-mode
  effect: changed
- type: command
  id: launch:desync-test
  effect: added
credit:
- ZivDero
- Rampastring
- dkeeton
---

An out-of-sync report used to be written as `SYNC<n>.TXT` in the working directory. It is now written to the `Debug` folder beside the executable, under a name that gives the local player's house, the date and time, and the frame. A machine writes at most one report per frame and three per game, and writing one no longer advances the game's random numbers.

The report now names every player whose checksum disagreed, with both machines' checksums, and records the session identity and seed so two players' reports can be matched. It identifies objects by IDs that are the same on every machine still in sync. Its histories of recent random draws, target assignments, mission orders, facing assignments, animation creations and events are limited in length and list the newest first. Each machine now compares checksums before it runs a frame's events, so two players' reports describe the same point in the game.

The new `-DESYNCTEST=<frame>` launch option spoils this machine's checksum once, at that frame or the first checked frame after it, so a report can be tested without a real divergence.

A recording that goes out of sync during playback shows "The game is out of sync." instead of "Reconnection Error!".

Rampastring is credited for the ts-patches state histories this follows and the Vinifera check that reads a frame's checksums before its events run. dkeeton is credited for the expanded ts-patches sync file this takes the FPU control word from.
