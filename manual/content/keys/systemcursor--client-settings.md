---
key: SystemCursor
scope: client-settings
label: System mouse pointer
when_omitted:
  kind: value
  value: "no"
---

`SystemCursor=yes` shows the Windows mouse pointer wherever the game would show its green arrow: over its menus and dialogs, and wherever no battlefield pointer is up. The battlefield pointers, such as the move and attack pointers, stay the game's own at either setting.

At `SystemCursor=no`, the arrow is `cursor.png` from the [UI files](/systems/ui-files/), enlarged by [`CursorScale`](/keys/cursorscale/) like the battlefield pointers. If that file is missing or cannot be read, the game shows the Windows pointer instead.

The Windows pointer keeps the size and colors set in Windows, so `CursorScale` does not change it. Use `SystemCursor=yes` when those settings make the pointer easier to see.

The display options screen has the same switch. Accepting that screen changes the pointer at once, and leaving the options menu saves the setting to `sun.ini`.
