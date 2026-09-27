---
key: Groundspeed
scope: housetype
label: Country speed multiplier
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1.0"
---

The objects of a house of this country have their top speed multiplied by this value, so a value above 1 moves them faster. It scales objects whose [`Locomotor=`](/keys/locomotor/) is Drive, Hover, Walk, Mech or Tunnel: driven vehicles, hovercraft, infantry, walkers and burrowing vehicles. Objects on any other locomotor, including aircraft and jumpjets, do not use it.

```ini title="rules.ini"
[NOD]
Groundspeed=1.2 ; example: NOD's ground objects travel 20% faster
```

Outside a campaign game, the house multiplies this value by [the difficulty section's `Groundspeed=`](/keys/groundspeed/#scope-difficulty-settings) and [`GameSpeedBias`](/keys/gamespeedbias/) once, [when it is given its difficulty slot](/systems/difficulty/#how-the-figures-are-combined). A campaign game leaves the country's value out and keeps the other two.
