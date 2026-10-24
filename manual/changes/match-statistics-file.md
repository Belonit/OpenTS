---
title: Write the match statistics file for ladder clients
category: feature
release: 0.2.0
targets:
- type: format
  id: stats-dmp
  effect: added
- type: format
  id: spawn-ini
  effect: changed
credit:
- ZivDero
- FunkyFr3sh
- Iran
- dkeeton
---

A game against other machines launched with `WriteStatistics=yes` in `spawn.ini` writes `stats.dmp` when the match is decided, for the CnCNet quick-match client to upload to the ladder. The file gives each player's name, result, country, color, start position and unit counts, the match number from `GameID`, and the map from `UIMapName` and `MapHash`. Its counts and match time carry over through saved games.

FunkyFr3sh, Iran and dkeeton wrote the ts-patches statistics file this follows.
