---
title: Keep units that cannot enter the shroud from rallying into it
category: fix
release: 0.2.0
targets:
- type: system
  id: production
  effect: changed
- type: key
  id: MoveToShroud
  effect: changed
- type: key
  id: AllowShroudedSubteranneanMoves
  effect: changed
credit: [ZivDero, dkeeton]
---

An object leaving a player's factory no longer heads for a rally point that is still shrouded for that player when its type cannot be ordered into the shroud. Such an object leaves as if the factory had no rally point, and objects that leave after the player uncovers the rally point follow it again. The affected types are those whose `rules.ini` section sets `MoveToShroud=no`. Subterranean types are also affected unless `AllowShroudedSubteranneanMoves=yes` is set under `[General]` in `rules.ini`.

dkeeton is credited for the ts-patches patch this follows, which refused such a rally point at the cursor instead and exempted every barracks.
