---
title: Keep Wakeup Group within the list of foot units
category: fix
release: 0.2.0
targets:
- type: action
  id: TACTION_WAKEUP_GROUP
  effect: changed
credit: [ZivDero, CCHyper, tomsons26]
---

Wakeup Group now checks only the map's infantry, vehicles and aircraft. It used to read past the end of their list, one entry for every structure on the map, with results that depended on whatever memory lay there. A map without structures behaves as before.

CCHyper and tomsons26 are credited for the Vinifera fix this follows.
