---
title: Judge the crate harvester rescue on the whole list
category: fix
release: 0.2.0
targets:
- type: system
  id: crates
  effect: changed
credit: [ZivDero, AlexB]
---

A unit crate can give a free harvester to a collector whose house owns a refinery and no harvester. The crate now counts every refinery in `BuildRefinery` under `[AI]` and every harvester in `HarvesterUnit` under `[General]` of `rules.ini`, where it used to count only the first entry of each. The harvester it gives is the first `HarvesterUnit` entry the collector's country may own, or the first entry when the country may own none.

When no vehicle type qualifies for the crate's random vehicle, for example because none with `CrateGoodie=yes` can be owned by the collector, the crate now gives nothing. It used to hang the game.

AlexB is credited for the ts-patches bundle that first read these lists whole.
