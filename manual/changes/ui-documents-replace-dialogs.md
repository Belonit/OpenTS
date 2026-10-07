---
title: Draw the dialogs as UI documents
category: feature
release: 0.2.0
targets:
- type: system
  id: ui-files
  effect: added
- type: key
  id: BitmapSystemFont
  effect: added
- type: command
  id: fixed:main-menu-version
  effect: changed
- type: format
  id: keyboard-ini
  effect: changed
credit:
- ZivDero
---

The screens the game built from dialog templates in `Language.dll`, including the classic main menu and the options menus, are now drawn from UI documents in the `ui` directory beside the executable. `Language.dll` no longer holds those templates. The score screens, the graphical main menu and the sidebar are drawn as before.

A screen keeps the controls, layout, artwork and sounds of the dialog it replaced, and opens with the same sliding animation. Where a picture is missing, the control draws a plain fill and the screen still opens.

A menu or modal dialog that cannot load a required UI file shows a native error message. Restore the `ui` folder supplied with the build beside the executable.

The skirmish setup opens even when its map list is empty.

When a screen is driven from the keyboard, the control that holds the focus is highlighted until the next mouse press. The old dialogs drew no focus mark.

Documents, style sheets and pictures are found by bare file name through the game's file system. A file of the same name in a folder the game searches before `ui` replaces the shipped one.

Text fields accept any character typed. A player whose keyboard writes Cyrillic, Greek or accented Latin can type their name and their messages, and the text fields draw those letters.

`BitmapSystemFont` under `[Options]` in `SUN.INI` chooses the face of the screens' lists, text boxes, tooltips, hotkey fields and group headings. At `yes` they use the bitmap face the old dialogs used, and at `no` the scalable face of the same design. The bitmap face cannot be resized, so even at `yes` it is used only where the game draws one screen pixel per game pixel.

Canceling the keyboard screen now drops the key assignments made in it. The old dialog kept them whenever `KEYBOARD.INI` was missing. A reset to the default keys takes effect as soon as it is confirmed, and canceling does not undo it.

Recordings made before this release no longer play back.
