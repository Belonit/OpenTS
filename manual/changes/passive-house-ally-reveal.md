---
title: Keep a passive house dark when it allies with the player
category: fix
release: 0.2.0
targets:
- type: key
  id: MultiplayPassive
  effect: changed
- type: key
  id: AllyReveal
  effect: changed
credit: [ZivDero, Rampastring]
---

Outside a campaign, the objects of a country with `MultiplayPassive=yes` in its `rules.ini` section reveal no ground, and an alliance with the player no longer changes that. With `AllyReveal=yes` in the `[AudioVisual]` section of `rules.ini`, which shares each house's sight with its allies, forming the alliance used to reveal the ground around every one of the passive house's objects once.
