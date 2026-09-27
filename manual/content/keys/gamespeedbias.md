---
key: GameSpeedBias
summary: The multiplier on every house's build time and ground movement speed.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "1"
---

The value multiplies every house's build time and the top speed of its ground objects. A value above 1 makes production slower and ground objects faster: at `1.1`, builds take about 10 percent longer and ground objects move about 10 percent faster.

Ground objects here are those whose [`Locomotor=`](/keys/locomotor/) is Drive, Hover, Walk, Mech or Tunnel. Aircraft and jumpjets keep their own speed. The value also multiplies the [`Airspeed=`](/keys/airspeed/) figures, but nothing reads them.

A house combines this value with its difficulty section's [`BuildTime=`](/keys/buildtime/#scope-difficulty-settings) and [`Groundspeed=`](/keys/groundspeed/#scope-difficulty-settings) [when it is given its difficulty](/systems/difficulty/#how-the-figures-are-combined). Outside a campaign, the country's [`BuildTime=`](/keys/buildtime/#scope-housetype) and [`Groundspeed=`](/keys/groundspeed/#scope-housetype) are combined in as well. Campaign games use this value too.
