---
key: Airspeed
scope: housetype
label: Country air-speed multiplier
see_also: ["system:difficulty", Groundspeed]
when_omitted:
  kind: value
  value: "1.0"
---

A house of this country combines this multiplier with [the difficulty section's `Airspeed=`](/keys/airspeed/#scope-difficulty-settings) and [`GameSpeedBias`](/keys/gamespeedbias/) [when it is given its difficulty slot](/systems/difficulty/#how-the-figures-are-combined). A campaign game leaves the country's value out, as it does for [`Groundspeed=`](/keys/groundspeed/#scope-housetype).

Nothing in the game reads the combined figure, so no value here changes how fast anything moves. An aircraft flies at [`Speed=`](/keys/speed/#scope-aircrafttype) in its aircraft type's section.
