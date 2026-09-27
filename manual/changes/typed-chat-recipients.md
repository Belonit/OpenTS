---
title: Message your team, or the other observers, and choose who a line reaches
category: feature
release: 0.2.0
breaking: true
migration:
- Remove `-MESSAGES` from any shortcut. The option is gone; a chat line is accepted only from a player or observer in the match.
targets:
- type: system
  id: chat
  effect: added
- type: command
  id: ChatToAll
  effect: added
- type: command
  id: ChatToAllies
  effect: added
- type: command
  id: fixed:multiplayer-message
  effect: changed
- type: command
  id: launch:messages
  effect: removed
- type: format
  id: keyboard-ini
  effect: changed
- type: system
  id: observers
  effect: changed
credit: [ZivDero, dkeeton, CCHyper]
---

In-game chat in a network game can now be sent to the sender's team, and an observer can send a line to the other observers. These join the lines to everyone and to one player that chat already had. By default Backspace starts a team line, or an observers line for an observer, and Enter starts a line to everyone. A `KEYBOARD.INI` that binds either key to another command, or either chat command to another key, keeps its bindings.

Each line now reaches only the players it is for. A team line reaches the houses the sender is allied with, and an observers line reaches only the other observers. A line from a machine that is not playing or observing in the match is dropped. The `-MESSAGES` switch, which let such lines through, is removed.

dkeeton is credited for the ts-patches team and observer chat this follows, and CCHyper for the Vinifera routing and echo.
