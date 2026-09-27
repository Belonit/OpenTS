---
title: Ask the whole war factory list who owns one
category: fix
release: 0.2.0
targets:
- type: key
  id: BuildWeapons
  effect: changed
credit: [ZivDero, AlexB]
---

A computer house that owns a refinery and sells its base to raise money now counts a structure of any type in the `BuildWeapons` list, under `[AI]` in `rules.ini`, as the war factory that lets it replace a harvester. Only the first two entries used to count, so such a house whose war factory came later in the list raised enough to replace a refinery instead. A one-entry list was read past its end, which could crash the game.

AlexB is credited for the ts-patches bundle that first read these lists whole.
