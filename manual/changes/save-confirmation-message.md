---
title: Report a completed save in the message list
category: feature
release: 0.2.0
targets:
- type: format
  id: save-games
  effect: changed
- type: command
  id: QuickSave
  effect: changed
credit:
- ZivDero
- Rampastring
---

A save the player asks for now reports `Game saved.` in the message list once the file is written, or `The game could not be saved.` when it fails. The line replaces the box that used to confirm the save. In a game against other machines, a save from the options menu used to report nothing. A save made from the menus is reported when the player returns to the map, and two players who save on the same frame share one save and one line.

An automatic save replaces its `Auto-saving...` line with `Game auto-saved.` when it succeeds, or with `The game could not be auto-saved.` when it fails. Saving settings in the random map generator still shows its own box.
