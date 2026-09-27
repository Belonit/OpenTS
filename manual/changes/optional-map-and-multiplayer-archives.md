---
title: Stop requiring the map and multiplayer archives
category: fix
release: 0.2.0
targets:
- type: format
  id: mix
  effect: changed
credit:
- ZivDero
---

The game now starts without any `MAPS*.MIX` archive and without `MULTI.MIX`, and mounts them when they are present. A deployment that kept its maps loose, or its multiplayer content in archives of its own, used to close during startup without an error message. `CACHE.MIX`, `CONQUER.MIX` and `SOUNDS.MIX` are still required, and so is `SOUNDS01.MIX` when Firestorm is installed.
