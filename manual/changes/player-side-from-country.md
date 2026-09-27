---
title: Take the presented side from the player's country
category: fix
release: 0.2.0
targets:
- type: key
  id: Player
  scope: scenarios-2
  effect: changed
- type: key
  id: SpeechSide
  effect: changed
credit: [ZivDero]
---

A mission's artwork, interface and voices now follow the side of the country that `Player=` names in the scenario's `[Basic]` section, and in a skirmish or network game the side of the country the player chose. Only GDI or Nod could be presented before: a mission checked whether `Player=` said `GDI`, a skirmish or network game used a GDI-or-Nod choice, and a country on a third side was presented as Nod. `SpeechSide=` in a campaign mission's `[Basic]` section, which picks the side whose voices play, could reach a third side, but only for voices. A saved game now records the player's country and side, so it loads with the same presentation.

A side whose archives are missing is now presented with the first side's archives. The scenario or saved game used to fail to load.
