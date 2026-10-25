---
key: Airspeed
scope: housetype
label: Country air-speed multiplier
see_also: ["system:difficulty", Groundspeed]
when_omitted:
  kind: value
  value: "1.0"
---

When a house of this country is given its difficulty slot, it multiplies this value by [the difficulty section's `Airspeed=`](/keys/airspeed/#scope-difficulty-settings) and [`GameSpeedBias`](/keys/gamespeedbias/). A campaign game leaves the country's value out, as it does for [`Groundspeed=`](/keys/groundspeed/#scope-housetype).

That figure multiplies the top speed of the house's objects on the flying locomotor, so a figure above 1 makes them fly faster.
