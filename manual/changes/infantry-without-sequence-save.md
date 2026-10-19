---
title: Save games with infantry types that have no sequence
category: fix
release: 0.2.0
targets:
- type: key
  id: Sequence
  effect: changed
credit: [ZivDero]
---

Saving a game failed with an error message when `[InfantryTypes]` listed a type whose `art.ini` image section has no `Sequence=`, as happens when the type's sections are commented out. Such a type now has empty animation sequences, and the game saves normally.
