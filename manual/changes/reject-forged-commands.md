---
title: Reject multiplayer commands the interface would refuse
category: fix
release: 0.2.0
targets:
- type: system
  id: network-packet-validation
  effect: changed
- type: system
  id: base-adjacency
  effect: changed
credit:
- ZivDero
---

In a network game, most interface rules were checked only on the machine of the player who gave the order. A modified game could therefore place buildings far from its base or under the shroud, drop a finished vehicle onto any cell, and start production without its prerequisites. It could also sell other players' walls and `Unsellable=yes` buildings, order a silo to launch without a charged superweapon, and break fixed alliances. Every machine now applies these rules when the command runs and ignores a command that breaks one. A command that an unmodified game cannot send also shows every player a message naming its sender.

A modified game could remove any other player from a network match with a single departure report. A player is now removed only once more than half of the other players in the match have reported the departure.

A modified game could also change the special game rules for everyone or place damaging animations anywhere on the map. In a network game these commands are now ignored, because no copy of the game sends them.
