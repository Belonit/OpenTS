---
title: Load structures owned by the local player in multiplayer
category: fix
release: 0.2.0
targets:
- type: format
  id: scenario-objects
  effect: changed
credit:
- ZivDero
- Iran
---

In skirmish and network games, a structure that a map's `[Structures]` section gives to the local player's house is now placed. Such a structure used to be skipped on its owner's machine and placed on every other machine, so the machines held different structures whenever a map gave one to a country a person was playing. Structures given to a spawn house now also reach the player who takes that house.

Iran is credited for the CnCNet spawner patch that lifts the same check.
