---
title: Play the Firestorm menu track only while Firestorm is running
category: fix
release: 0.2.0
targets:
- type: system
  id: music
  effect: changed
credit: [ZivDero]
---

The main menu played `FSMENU` whenever Firestorm was installed, including in a Tiberian Sun game. It now plays `FSMENU` only while Firestorm is running and `INTRO` otherwise.
