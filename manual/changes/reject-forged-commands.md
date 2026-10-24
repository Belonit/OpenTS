---
title: Reject multiplayer commands the game never sends
category: fix
release: 0.2.0
targets:
- type: system
  id: network-packet-validation
  effect: changed
credit:
- ZivDero
---

A modified game could remove any other player from a network match with a single departure report, and every machine carried out the removal. A player is now removed only once more than half of the other players in the match have reported the departure.

A modified game could place a building anywhere on the map, far from its base or under the shroud, and could drop a finished vehicle or infantry onto any cell. Every machine now repeats the placement cursor's base distance and shroud rules when a building is placed, and ignores a placement that fails them.

A modified game could also change the special game rules for everyone or place damaging animations anywhere on the map. In a network game these commands are now ignored, because no copy of the game sends them.
