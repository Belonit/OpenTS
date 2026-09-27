---
title: Show the loading picture a launch file names
category: feature
release: 0.2.0
targets:
- type: format
  id: spawn-ini
  effect: changed
credit:
- ZivDero
- Rampastring
- CCHyper
---

`CustomLoadScreen` in `[Settings]` of `SPAWN.INI` names the picture shown while the scenario loads, replacing the one the game picks by the player's side and screen size. If no file has that name, the game shows its usual picture.

`CustomLoadScreenPos` in the same section places the loading bars, measured from the top-left corner of that picture, when both of its numbers are above 0. The picture is centered on the screen, so one position works at every screen size.
