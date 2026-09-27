---
key: Target
summary: Parsed trap target that reaches a routine with nothing in it.
no_effect: true
see_also: ["Coord", "Cell", "Type", "Frame"]
when_omitted:
  kind: value
  value: "-1"
---

The value is an encoded number that identifies an object to watch. The engine decodes and stores it, but nothing compares any object against it, because the search that would do so is compiled out of both build configurations.

`Target` is one of the [sync-bug settings](/systems/developer-mode/#the-sync-dump). They are read only when the player picks multiplayer play from the main menu in a Debug build started with [`-XY`](/using/command-line/playback/).
