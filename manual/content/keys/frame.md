---
key: Frame
summary: Parsed trap frame that reaches a routine with nothing in it.
no_effect: true
see_also: ["Type", "Target", "Cell", "Coord", "PrintCRC"]
when_omitted:
  kind: value
  value: "2147483647"
---

The value names the game frame from which the object described by the other sync-bug settings would be watched. The watching code is built into neither configuration, so reaching the frame changes nothing.

`Frame` is one of the [sync-bug settings](/systems/developer-mode/#the-sync-dump). They are read only when the player picks multiplayer play from the main menu in a Debug build started with [`-XY`](/using/command-line/playback/).
