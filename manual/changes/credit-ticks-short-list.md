---
title: Accept a CreditTicks list with fewer than two sounds
category: fix
release: 0.2.0
targets:
- type: key
  id: CreditTicks
  effect: changed
credit: [ZivDero, CCHyper]
---

A `CreditTicks=` list with fewer than two valid sounds used to crash the game or play the wrong sound when the player's money changed. A missing sound is now silent: with no entries the credit readout counts silently, and with one entry it ticks only while the figure rises.

CCHyper is credited for the Vinifera fix this follows.
