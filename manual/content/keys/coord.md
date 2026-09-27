---
key: Coord
summary: Parsed trap coordinate that is thrown away as soon as it is read.
no_effect: true
see_also: ["Cell", "Target", "Type", "Frame"]
when_omitted:
  kind: value
  value: "0"
  note: A written value is discarded as it is read, so omitting the key gives the same result as writing it.
---

The value is meant to be the world coordinate of an object to watch, written as three comma-separated numbers.

`Coord` is one of the [sync-bug settings](/systems/developer-mode/#the-sync-dump). They are read only when the player picks multiplayer play from the main menu in a Debug build started with [`-XY`](/using/command-line/playback/).
