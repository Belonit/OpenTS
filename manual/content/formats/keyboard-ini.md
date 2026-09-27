---
format_id: keyboard-ini
title: KEYBOARD.INI
summary: Maps registered command names to integer keyboard identifiers.
kind: file
filenames:
  - KEYBOARD.INI
source_files:
  - code/init.cpp
  - code/keyboard.h
  - code/options.cpp
---

Each assignment in `[Hotkey]` binds a key to a command. The name before `=` is the command's exact [registered name](/commands/), including its case. The value is a keyboard identifier: the key's Windows virtual-key code, plus 256 for Shift, 512 for Control and 1024 for Alt.

```ini title="KEYBOARD.INI"
[Hotkey]
SelectView=577      ; A with Control
ToggleRepair=338    ; R with Shift
ScatterObject=88    ; X
```

A command name can appear only once in the section, so the file gives each command at most one key. If a name is repeated, the later value is used.

The game reads the file at startup. A loose `KEYBOARD.INI` in the game directory replaces one inside an archive. An entry is ignored if its command name is not registered or its value is `0`.

A file that holds at least one section header replaces all current bindings. If no `KEYBOARD.INI` is found, or the file has no section header, the current bindings stay. At startup that leaves only the built-in keys described below.

The keyboard dialog saves the bindings the player accepts to a loose `KEYBOARD.INI`, and canceling it discards the changes. Its reset control deletes the loose file at once, even if the dialog is then canceled, and reads `KEYBOARD.INI` again. The bindings are replaced only if the game still finds one, such as a copy inside an archive.

After reading the file at startup, the game binds Delete to [`DeleteWaypoint`](/commands/deletewaypoint/) and Escape to [`Options`](/commands/options/). If the file binds either key, one binding for that key is removed, so a key the file binds once goes only to the built-in command. A key the file gives either command is kept, so that command can have two keys.

At startup the game also binds Enter to [`ChatToAll`](/commands/chattoall/) and Backspace to [`ChatToAllies`](/commands/chattoallies/), each only when the file binds neither that command nor that key. A file that binds the command to another key, or gives the key to another command, keeps its binding.

:::caution[Bind each key once]
Give each key to only one command. If two entries bind the same key, both are kept, and pressing the key runs only one of the two commands. Which one runs cannot be predicted from the file.
:::
