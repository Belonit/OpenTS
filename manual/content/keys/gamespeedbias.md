---
key: GameSpeedBias
summary: The multiplier on every house's build time and movement speed.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "1"
---

The value multiplies every house's build time and the top speed of its vehicles, infantry and aircraft. A value above 1 makes production slower and objects faster: at `1.1`, builds take about 10 percent longer and objects move about 10 percent faster.

It scales objects whose [`Locomotor=`](/keys/locomotor/) is Drive, Hover, Walk, Mech, Tunnel or Fly. Jumpjets keep their own speed.

A house combines this value with its difficulty section's [`BuildTime=`](/keys/buildtime/#scope-difficulty-settings), [`Groundspeed=`](/keys/groundspeed/#scope-difficulty-settings) and [`Airspeed=`](/keys/airspeed/#scope-difficulty-settings) [when it is given its difficulty](/systems/difficulty/#how-the-figures-are-combined). Outside a campaign, the country's [`BuildTime=`](/keys/buildtime/#scope-housetype), [`Groundspeed=`](/keys/groundspeed/#scope-housetype) and [`Airspeed=`](/keys/airspeed/#scope-housetype) are combined in as well. Campaign games use this value too.
