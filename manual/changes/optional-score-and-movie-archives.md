---
title: Stop requiring the score and movie archives
category: fix
release: 0.2.0
targets:
- type: format
  id: mix
  effect: changed
credit: [ZivDero, FunkyFr3sh]
---

The game now starts when `SCORES.MIX` is missing or no `MOVIES*.MIX` archive is found; it used to refuse to start. An archive that is present is still mounted. A music track or movie whose file is in no mounted archive or search folder is skipped.

FunkyFr3sh is credited for the ts-patches change this follows.
