---
title: Keep a player's own files in a directory named on the command line
category: feature
release: 0.2.0
targets:
- type: command
  id: launch:user-directory
  effect: added
credit: [ZivDero]
---

`-USERDIR=<path>` names the directory the game writes the player's files to: the settings file, hotkeys, saved games, the hall of fame, recordings, saved random maps, screenshots and the files a multiplayer game downloads. The game creates the directory if it does not exist. Saved games go to a `Saved Games` folder and screenshots to a `Screenshots` folder inside it. Without the option, all of these files are written to the game's directory, with saved games and screenshots still in those two folders.

A file in the user directory is read before any other file of the same name, so the player's copy wins over one a deployment ships. Until the player's copy exists, the game reads the shipped one. Deleting a file removes only the player's copy, so resetting the hotkeys falls back to the hotkeys the deployment shipped.
