---
title: Keep a shroud and fog for every house
category: feature
release: 0.2.0
targets:
- type: system
  id: map-visibility
  effect: changed
- type: key
  id: AllyReveal
  effect: changed
credit: [ZivDero]
---

Every house now has its own shroud and fog. Before, only the local player's existed.

`AllyReveal=yes` under `[AudioVisual]` in `rules.ini` lets a house see what its allies' objects see.

Outside a campaign, shroud and fog regrowth no longer covers ground that these objects see:

- an ally's vehicles and infantry, while `AllyReveal=yes`;
- the vehicles, infantry and structures of a house whose radar the player has spied on;
- an object carrying the player's limpet drone.

Before, regrowth spared only what an ally's structures saw while `AllyReveal=yes`, and fog regrowth could still cover part of that.

Outside a campaign, the same objects, other than structures, now also uncover ground when the playable area grows to include them. In a campaign, both regrowth and a growing playable area work as before.

While `AllyReveal=yes`, the player now also sees what an ally's airborne infantry, tile-laying structures and newly captured structures see, and what an object carrying an ally's limpet drone sees. For a house whose radar the player has spied on, the player also sees what its aircraft, airborne infantry, tile-laying structures and newly captured structures see.
