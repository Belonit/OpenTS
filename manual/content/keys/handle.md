---
key: Handle
summary: The player name remembered between runs and offered back by the multiplayer dialogs.
see_also: ["Color", "Side"]
when_omitted:
  kind: value
  value: "[NONAME]"
  note: The English placeholder text; a localized build supplies its own.
---

The game reads the name when the player picks multiplayer play from the main menu and puts it in the name field of the LAN and skirmish dialogs. Leaving either dialog saves the name, including any edit made there, back to `sun.ini`.

When the player hosts a LAN game, other players see the game listed under this name.

The stored name can be up to 63 bytes of UTF-8 text. The LAN dialog's name field accepts 16 typed characters, and the skirmish dialog's accepts 11.

A game started from a [client launch file](/formats/spawn-ini/#who-is-playing) uses the name written there and leaves the stored name unchanged.
