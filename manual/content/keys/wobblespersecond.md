---
key: WobblesPerSecond
summary: How many complete up-and-down cycles a hovering jumpjet unit performs each second.
see_also: [WobbleDeviation, CruiseHeight]
when_omitted:
  kind: value
  value: ".25"
---

`WobblesPerSecond` sets how fast a flying jumpjet bobs above and below its flight height. The value is the number of full cycles per second at 15 frames a second: one cycle takes 15 frames divided by this value. At the default `.25`, a jumpjet takes 60 frames, four seconds at 15 frames a second, to rise, fall and come back. [`WobbleDeviation`](/keys/wobbledeviation/) sets how far it moves in that time.

```ini title="rules.ini"
[JumpjetControls]
WobblesPerSecond=.15
```

The wave advances only while the jumpjet is hovering or cruising. Taking off, descending and standing on the ground restart it from its midpoint, so every jumpjet starts bobbing from the same point.

`0` stops the bobbing, and the jumpjet holds its flight height. A negative value runs the wave backward, so the jumpjet dips before it rises.
