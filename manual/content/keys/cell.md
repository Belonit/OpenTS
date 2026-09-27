---
key: Cell
summary: Parsed trap cell that nothing ever reads back.
no_effect: true
see_also: ["Coord", "Target", "Type", "Frame"]
when_omitted:
  kind: value
  value: "0,0"
---

The value names a map cell as two comma-separated numbers, such as `40,52`. The engine keeps a reference to that cell and never uses it. `0,0` names no cell.

`Cell` is one of the [sync-bug settings](/systems/developer-mode/#the-sync-dump). They are read only when the player picks multiplayer play from the main menu in a Debug build started with [`-XY`](/using/command-line/playback/).
