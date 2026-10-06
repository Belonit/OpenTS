---
title: Serialize save games member by member
category: internal
release: 0.1.0
breaking: true
migration:
- Finish existing games in Tiberian Sun before switching to OpenTS. Tiberian Sun saves cannot be loaded or converted in OpenTS.
targets:
- type: format
  id: save-games
  effect: changed
credit: [ZivDero]
---

Saved games now store individual members instead of object memory. Vanilla Tiberian Sun saves and saves from another OpenTS release version cannot be loaded.

Loading resets the power bar, radar animation and cursor to their resting states, and no longer restores internet-game tallies.
