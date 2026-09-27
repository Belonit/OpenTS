---
title: Carry the country behind each lobby side entry
category: fix
release: 0.2.0
targets:
- type: key
  id: Side
  scope: multiplayer-settings
  effect: changed
credit: [ZivDero]
---

The skirmish and LAN side boxes now give the player the country picked in them, wherever that country sits in the rules. Both boxes used to take the entry's position in the box as the country, which matched only while the `Multiplay=yes` countries came first in `[Houses]`; otherwise a player could pick one country and play another. The skirmish box also switched a country remembered in `Side=` under `[MultiPlayer]` in `sun.ini` to the second entry whenever that country came after the second country in `[Houses]`.

The LAN player list now picks a player's icon by the country's side. Countries of the first side show the first side's icon and label, and all other countries show the second side's; a country of a third side is labeled with its own name. The list used to give the first side's icon and label only to the first country in `[Houses]`.
