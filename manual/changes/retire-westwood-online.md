---
title: Retire Westwood Online
category: feature
release: 0.2.0
breaking: true
migration:
- Play over a network or in skirmish instead. A Westwood Online game can no longer be started, and the World Domination Tour it hosted can no longer be entered.
- Delete the `[WOnline]` section from `sun.ini`, along with `PreferredServer`, `Locale`, `StoreNick` and `LastNickSlot` from `[MultiPlayer]`, or leave them to be ignored.
- Assign another command to the key that was set to Page User if you want to use it. That key now does nothing, because the command is gone and the `[Hotkey]` entry in `keyboard.ini` that names it is ignored.
targets:
- type: command
  id: PageUser
  effect: removed
- type: key
  id: AllowFind
  effect: removed
- type: key
  id: AllowPage
  effect: removed
- type: key
  id: LangFilter
  effect: removed
- type: key
  id: LobMusic
  effect: removed
- type: key
  id: ShowAll
  effect: removed
- type: key
  id: LastNickSlot
  effect: removed
- type: key
  id: Locale
  effect: removed
- type: key
  id: PreferredServer
  effect: removed
- type: key
  id: StoreNick
  effect: removed
credit: [ZivDero]
---

The Westwood Online client has been removed with its login, chat lobby, ladder and paging screens. The Internet button stays on the main menu and in the Select Multiplayer Game menu, but it is disabled. On Firestorm, the World Domination Tour buttons are disabled as well, because the tour was played through the same service.

Network and skirmish games are unaffected.
