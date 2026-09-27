---
title: Leave observers the whole map on Reshroud
category: fix
release: 0.2.0
targets:
- type: action
  id: TACTION_RESHROUD
  effect: changed
- type: mission
  id: TMISSION_RESHROUD
  effect: changed
- type: system
  id: observers
  effect: changed
credit: [ZivDero]
---

The Reshroud map action and team mission no longer shroud an observer, or a player defeated while coach mode is off. Before, each machine shrouded the map for the player it was running, so an observer saw only shroud until the map was revealed again.
