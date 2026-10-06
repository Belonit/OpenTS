---
title: Search the folders a deployment keeps its files in
category: feature
release: 0.2.0
breaking: true
migration:
- If `INI`, `MIX` or `Maps` folders contain files the game should not load, set `SearchPaths=.` under `[Paths]` in `OPENTS.INI`, or rename those folders.
targets:
- type: format
  id: opents-ini
  effect: added
credit: [ZivDero]
---

A deployment can now keep its files in folders and list them in `SearchPaths` under `[Paths]` in `OPENTS.INI`. Without that setting the game searches the `INI`, `MIX` and `Maps` folders, so a deployment sorted into those folders needs no configuration.

A search by file pattern used to stop at the first folder holding a match. The searches for campaign files, map packs, loose multiplayer maps, and map and movie archives now collect matches from every searched folder. A name found in more than one folder is taken from the folder searched first, whatever order the file system lists files in. The loose `PATCH.MIX` and `EXPAND??.MIX` archives are now found in any searched folder, where only the game's own directory used to count, and are still never read from inside another archive.

The settings file, the hotkey file, the hall of fame and a saved random map used to be written back to whichever copy the search found. A copy shipped in a searched folder could therefore be overwritten, and resetting the hotkeys could delete it. The game now writes and deletes files only in the user data directory, or in the game's own directory when there is none.

When the first-run intro is due, the game now saves `PlayIntro=no` under `[Intro]` in the settings file, so the intro plays only once. That save used to fail, so the intro played again at every start.
