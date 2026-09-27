---
command_id: fixed:debug-special-dialog
---

The `/` key never opens a dialog, because the special dialog it was meant to open is not part of the game. What happens instead depends on the kind of game.

In a campaign, the key does nothing.

:::danger[Do not press `/` outside a campaign]
In any other game, skirmish included, the key pauses the game and the game stops responding. It never resumes, and the game has to be closed from outside. The key does nothing when the local player is already winning or losing.

To make the key safe, bind `/` to a command in [`KEYBOARD.INI`](/formats/keyboard-ini/). The key then runs that command and never pauses the game.
:::

[Developer mode and diagnostics](/systems/developer-mode/#arming-the-debug-keys) explains how a Debug build arms its debug keys.
