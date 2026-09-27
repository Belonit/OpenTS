---
format_id: ui-ini
title: UI.INI
summary: Sets how a selected object's order lines and a firing vehicle's sighting laser are drawn.
kind: file
source_files:
  - code/uicontrol.cpp
  - code/init.cpp
filenames:
  - UI.INI
key_scopes:
  - file: ui.ini
    section:
      kind: literal
      name: Ingame
related:
  - type: system
    id: action-lines
  - type: format
    id: opents-ini
  - type: using
    id: configuration-files
---

The file is optional and every key has a default, so a file names only what it changes. All keys go in one section, `[Ingame]`. The values below are examples.

```ini title="UI.INI"
[Ingame]
AlwaysShowActionLines=yes
MovementLineDashed=yes
MovementLineColor=0,255,0
NavComQueueLineThick=yes
```

Write a color as three numbers from 0 to 255 for red, green and blue, separated by commas. A color value that does not start with three comma-separated numbers keeps the default. Anything after the third number is ignored. [Action lines](/systems/action-lines/) explains what each line is and when it is drawn.

## When the file is read

The game reads the file at startup, after it registers the game archives. It reads the file again each time a scenario or saved game loads, after mounting the archives of the player's side, so a copy inside a side's archive applies to games played as that side. Each read starts from the defaults, so only the keys in the copy read last take effect.

The file is opened through the game's file search, so it may be a loose file in any folder the game searches or be inside an archive. A loose copy is used ahead of an archived one. [OPENTS.INI](/formats/opents-ini/#the-order-files-are-searched-for-in) lists the folders and the order they are searched in, and its [`[Files]` section](/formats/opents-ini/#the-files-it-reads) can change the file name.
