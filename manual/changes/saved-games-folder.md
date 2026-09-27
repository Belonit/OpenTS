---
title: Keep saved games in a folder of their own
category: feature
release: 0.2.0
targets:
- type: format
  id: save-games
  effect: changed
credit: [ZivDero, Rampastring]
---

Saved games are now written to, listed from and loaded from a `Saved Games` folder, beside the game or in the user directory when one is named. Settings saved from the random map generator go there too.

Saves made by earlier releases stay beside the game. This release cannot load them.

The missions that follow a loaded campaign save are now played at the difficulty stored in the save. They used to take the difficulty set in the menu.

Rampastring is credited for the ts-patches patch of the same name.
