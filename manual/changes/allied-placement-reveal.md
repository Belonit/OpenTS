---
title: Reveal an ally's structure the moment it is placed
category: fix
release: 0.2.0
targets:
- type: system
  id: map-visibility
  effect: changed
- type: key
  id: AllyReveal
  effect: changed
credit: [ZivDero, Rampastring]
---

Outside a campaign, a structure that an ally places now lifts the player's shroud around it as soon as it is placed. It used to leave that ground shrouded for the player. The reveal follows `AllyReveal` under `[AudioVisual]` in `rules.ini`, which shares allies' vision; with `AllyReveal=no`, an ally's new structure reveals nothing to the player. Campaigns are unchanged.
