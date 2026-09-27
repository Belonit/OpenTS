---
key: Groundspeed
scope: difficulty-settings
label: Difficulty speed multiplier
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1"
  note: The difficulty block is re-read from fixed defaults whenever its section is present, so a later file that contains the section without this key restores 1 rather than keeping the earlier value.
---

`[Easy]`, `[Normal]` and `[Difficult]` each set their own multiplier, and a house takes the one for [its difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot). The house's objects have their top speed multiplied by it, so a value above 1 moves them faster. Veterancy and the object's current throttle still apply on top. The multiplier scales objects whose [`Locomotor=`](/keys/locomotor/) is Drive, Hover, Walk, Mech or Tunnel. Objects on any other locomotor, including aircraft and jumpjets, take their speed from elsewhere, and this multiplier does not scale them.

```ini title="rules.ini"
[Difficult]
Groundspeed=1.2 ; example: ground objects on this difficulty travel 20% faster
```

[When the house is given its slot](/systems/difficulty/#how-the-figures-are-combined), it multiplies this value by [`GameSpeedBias`](/keys/gamespeedbias/) and, outside a campaign game, by [its country's `Groundspeed=`](/keys/groundspeed/#scope-housetype).
