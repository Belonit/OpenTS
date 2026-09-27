---
title: Name the difficulty a campaign mission is played at
category: feature
release: 0.2.0
targets:
- type: system
  id: difficulty
  effect: changed
- type: format
  id: spawn-ini
  effect: changed
credit:
- ZivDero
- Rampastring
- CCHyper
- dkeeton
---

A campaign mission now shows its difficulty in the on-screen message list when it starts. The name describes how hard the mission is for the player, so it runs opposite to the `rules.ini` section the computer houses use: `[Easy]` is announced as Hard, `[Normal]` as Medium and `[Difficult]` as Easy.

`DifficultyName` under `[Settings]` in a launch file replaces the announced name. A client that offers more than the game's three difficulties can use it to name the one the player chose.
