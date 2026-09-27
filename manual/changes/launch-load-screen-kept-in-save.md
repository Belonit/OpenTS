---
title: Keep a launch file's loading screen through a restart and a save
category: fix
release: 0.2.0
targets:
- type: format
  id: spawn-ini
  effect: changed
credit: [ZivDero]
---

A save now records the loading picture and bar position that the game's launch file set with `CustomLoadScreen` and `CustomLoadScreenPos` under `[Settings]`. Restarting a mission resumed from such a save shows that picture even when the current session has no launch file, or has one that names no picture; it used to show the game's own loading picture. Only the first restart after the resume keeps the picture.
