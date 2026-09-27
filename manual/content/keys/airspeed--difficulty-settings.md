---
key: Airspeed
scope: difficulty-settings
label: Difficulty air-speed multiplier
see_also: ["system:difficulty", Groundspeed, Speed]
when_omitted:
  kind: value
  value: "1"
  note: The difficulty block is re-read from fixed defaults whenever its section is present, so a later file that contains the section without this key restores 1 rather than keeping the earlier value.
---

`[Easy]`, `[Normal]` and `[Difficult]` each set their own multiplier. A house combines the one for [its difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot) with [`GameSpeedBias`](/keys/gamespeedbias/) and, outside a campaign game, with [its country's `Airspeed=`](/keys/airspeed/#scope-housetype).

Nothing in the game reads the combined figure, so no value here changes how fast anything moves. An aircraft flies at its type's [`Speed=`](/keys/speed/#scope-aircrafttype). The difficulty multiplier that does change movement speed is [`Groundspeed=`](/keys/groundspeed/#scope-difficulty-settings), and it does not scale aircraft either.
