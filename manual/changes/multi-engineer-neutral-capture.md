---
title: Let one engineer capture a Neutral structure under Multi Engineer
category: balance
release: 0.2.0
targets:
- type: system
  id: capture
  effect: changed
credit: [ZivDero, Rampastring]
---

With the multiplayer engineer option on, one engineer now captures a `Neutral` structure at any strength when the structure's `rules.ini` section sets `Capturable=yes`, as it does with the option off. Before, the option made the engineer damage it like any other house's structure, so taking it needed several engineers. Structures of every other house still take engineer damage while their strength is above `ConditionRed` under `[AudioVisual]` in `rules.ini`.
