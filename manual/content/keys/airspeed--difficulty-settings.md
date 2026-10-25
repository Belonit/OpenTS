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

`[Easy]`, `[Normal]` and `[Difficult]` each set their own multiplier. A house multiplies the value for [its difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot) by [`GameSpeedBias`](/keys/gamespeedbias/) and, outside a campaign game, by [its country's `Airspeed=`](/keys/airspeed/#scope-housetype).

That figure multiplies the top speed of the house's objects on the flying locomotor, so a figure above 1 makes them fly faster. Veterancy and the object's current throttle still apply on top. [`Groundspeed=`](/keys/groundspeed/#scope-difficulty-settings) scales ground objects instead.
