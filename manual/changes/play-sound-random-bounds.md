---
title: Keep Play Sound Effect (Random) within its waypoint list
category: fix
release: 0.2.0
targets:
- type: action
  id: TACTION_PLAY_SOUND_RANDOM
  effect: changed
credit: [ZivDero, CCHyper]
---

In a scenario that places every waypoint, the Play Sound Effect (Random) action could write past the end of its waypoint list and corrupt memory. It now chooses among the first 100 placed waypoints. In a scenario with no placed waypoint, it plays nothing, where it used to play the sound at cell `0,0` or at an arbitrary position.

CCHyper is credited for the Vinifera fix this follows.
