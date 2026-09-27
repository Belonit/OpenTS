---
title: Name the deployment's own files in OPENTS.INI
category: feature
release: 0.2.0
targets:
- type: format
  id: opents-ini
  effect: changed
- type: format
  id: sound-ini
  effect: changed
- type: format
  id: theme-ini
  effect: changed
- type: format
  id: tutorial-ini
  effect: changed
- type: format
  id: ui-ini
  effect: changed
credit:
- ZivDero
---

`OPENTS.INI` can name the game data files a deployment uses, under `[Files]` and `[Palettes]`. These include the rules, artwork, AI, sound, music, campaign and translated rules files, each with its expansion copy. They also include the tutorial text, the interface file, the settings file a player's options are saved to, and the two palettes the game starts with. A file the deployment does not name keeps its Tiberian Sun name. The game treats the expansion as installed when the expansion rules file named here is present.

A palette file the game cannot find now leaves that palette unchanged. It used to crash the game at startup.
