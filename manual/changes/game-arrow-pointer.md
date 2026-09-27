---
title: Show the game's green arrow outside the battlefield
category: feature
release: 0.2.0
targets:
- type: key
  id: SystemCursor
  effect: added
- type: key
  id: CursorScale
  effect: changed
- type: system
  id: ui-files
  effect: changed
credit:
- ZivDero
---

Over the game's menus and dialogs, and wherever no battlefield pointer is up, the pointer is now the game's green arrow, enlarged like the battlefield pointers. It was a black and white arrow at a fixed size. The arrow is `cursor.png` in the `ui` directory, so a mod can replace it. `SystemCursor=yes`, or the switch on the display options screen, shows the Windows pointer there instead.
