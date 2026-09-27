---
key: CheckHeap
summary: Parsed heap check switch that the engine never acts on.
no_effect: true
see_also: ["Frame", "PrintCRC"]
when_omitted:
  kind: value
  value: "0"
---

No heap check runs, whatever the value. The engine reads it when the player picks multiplayer play from the main menu, in either build configuration and with or without [`-XY`](/using/command-line/playback/).
