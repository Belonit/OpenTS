---
title: Replace the radar player list with a diplomacy panel
category: feature
release: 0.2.0
targets:
- type: system
  id: diplomacy
  effect: added
- type: command
  id: Diplomacy
  effect: added
- type: command
  id: ToggleRadar
  effect: removed
- type: command
  id: fixed:map-zoom
  effect: removed
- type: system
  id: chat
  effect: changed
breaking: true
credit:
- ZivDero
---

Tab used to switch the radar pane to a list of player names and kills. The `Diplomacy` command now opens a panel over the running game that lists every player with their kills, both sides of each alliance and of shared control, chat recipients and mute, latency, and the players the game keeps waiting on. Players change alliances and grants by ticking a box on the panel.

The radar pane no longer shows the list. A `ToggleRadar` binding in `KEYBOARD.INI` binds `Diplomacy`, and Tab does nothing unless the keyboard file gives it a command.
