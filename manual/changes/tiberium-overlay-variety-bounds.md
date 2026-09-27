---
title: Fix Tiberium on the large-crystal set and on slopes
category: fix
release: 0.2.0
targets:
- type: system
  id: tiberium
  effect: changed
- type: key
  id: Image
  scope: tiberium
  effect: changed
credit:
- ZivDero
- Rampastring
- dkeeton
---

A Tiberium type on `Image=2`, the large-crystal set, now has twelve growth stages instead of one, so it can grow, spread and yield several loads per cell. The stock `Cruentus` still neither grows nor spreads. A mod that wants the set harvested must also give its overlays a land type that harvesting accepts, because the shipped ones are `Land=Rock`.

That set has no slope artwork, so a type on it now draws nothing on a slope, including a type moved onto the set by a later file. It used to crash with a division by zero or draw overlays from outside its set.

Tiberium a map places on a corner, steep or double slope is now removed when the map loads. It used to be drawn with another set's overlay and could crash the game. No shipped map places Tiberium there.

Rampastring and dkeeton are credited for the ts-patches fix that gave the large-crystal set twelve stages.
