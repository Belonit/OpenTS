---
title: Save and load a quick save from the keyboard
category: feature
release: 0.2.0
targets:
- type: command
  id: QuickSave
  effect: added
- type: command
  id: QuickLoad
  effect: added
- type: format
  id: save-games
  effect: changed
credit: [ZivDero]
---

Two commands save and load a campaign or skirmish game without the options menu. Quick Save writes `QUICKSAVE.SAV` in a campaign or `QUICKSAVE_SKIRMISH.SAV` in a skirmish and reports the result in the message list. Quick Load restores that file for the current kind of game, or reports that there is none when it is missing or was written by another version.

Neither command has a default key. Neither works in a network game, while a recording plays back, while input is locked, or once the game is being won or lost.
