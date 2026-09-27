---
title: Let a type set how many pips its row has
category: feature
release: 0.2.0
targets:
- type: key
  id: MaxPips
  effect: added
- type: key
  id: PipScale
  effect: changed
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, Rampastring]
---

`MaxPips=` in a vehicle, infantry, aircraft or structure type's `rules.ini` section sets how many pips its [`PipScale`](/keys/pipscale/) row shows when the object is selected. Without it, the row keeps the length it had before, which for a structure's `Tiberium` or `Power` row depends on the structure's width. An `Ammo` or `Passengers` row still shows no more pips than the type's `Ammo=` or `Passengers=`, and a structure's `Tiberium` row no more than its storage.
