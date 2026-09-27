---
title: Stop drawing starting units when nothing is left to draw
category: fix
release: 0.2.0
targets:
- type: key
  id: AllowedToStartInMultiplayer
  effect: changed
credit: [ZivDero, CCHyper, JoyfulShush]
---

Rules that set `AllowedToStartInMultiplayer=no` on every InfantryType and on every UnitType except the base unit no longer crash a multiplayer game while it sets up. Each house now starts with its base unit alone when bases are on, and with no units when they are off.

A house also crashed the game when it ran out of types to start with. That happened when every allowed type was above its tech level or not ownable by its country, or when two thirds of its starting budget was spent and no infantry type was left for it. Such a house now keeps the units it already has.

CCHyper is credited for the Vinifera guard on the average price this one follows, and JoyfulShush for the Vinifera guard on the draw.
