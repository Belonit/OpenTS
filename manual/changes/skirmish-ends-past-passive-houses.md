---
title: End a team skirmish when only allies remain
category: fix
release: 0.2.0
targets:
- type: key
  id: MultiplayPassive
  effect: changed
- type: system
  id: observers
  effect: changed
credit: [ZivDero, dkeeton]
---

A skirmish now ends when every house left is allied, as a multiplayer game already did. In a skirmish the test used to count `MultiplayPassive=yes` houses such as `Neutral`, which is not defeated when it runs out of objects and is normally allied with no player. A skirmish in which the player had an allied computer house therefore went on after the last enemy fell.

dkeeton is credited for the ts-patches change this follows.
