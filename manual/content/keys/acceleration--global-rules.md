---
key: Acceleration
scope: global-rules
label: Jumpjet acceleration
see_also: [Speed, TurnRate, Climb]
when_omitted:
  kind: value
  value: ".25"
---

The jumpjet locomotor keeps a speed counter and moves the unit that many leptons along its current facing every game frame. This figure is how much the counter gains each frame while it is below the speed the current flight state asks for. The counter never goes past [`Speed`](/keys/speed/#scope-global-rules), the ceiling every jumpjet shares. There are 256 leptons to a cell and 15 game frames to the second.

The counter sheds speed faster than it gains it. When the flight state asks for less than the counter holds, the counter drops by one and a half times this figure per frame, down to a floor of zero. This is how quickly a jumpjet throttles back to the slower bands it uses near its destination, which the `Speed` page lists. On arrival the counter is zeroed outright, whatever this figure.

Once the counter is at or below a slower band, the unit never moves faster than that band. A gain that would pass the band is cut back in the same frame, before the unit moves. When the gains cannot land on the band exactly, a jumpjet at its flight height cycles through speeds up to one and a half times this figure below the band.

A jumpjet flying low has a lower top speed. While it is below about half its flight height and not yet over its destination cell, the counter loses a tenth of its value every frame after the gain. Its speed therefore cannot rise above about nine times this figure, which is about 2 leptons per frame at the default. Below about a quarter of its flight height the counter loses a second tenth, and the limit falls to about four times this figure. Height here is measured above the ground or structure under the unit and in the cell ahead, so rising terrain or a structure ahead also slows it.

```ini title="rules.ini"
[JumpjetControls]
Acceleration=2
Speed=14
```

With these values, a jumpjet at its flight height reaches full speed seven frames after it starts building speed, and throttles back by three leptons per frame.

:::caution[At `Acceleration=0` a jumpjet hovers and never sets off]
The counter is the only thing that moves the unit, and nothing else raises it. At `Acceleration=0` the counter never leaves zero, so a jumpjet climbs to its flight level, turns toward its destination and hovers there without ever setting off.
:::
