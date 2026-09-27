---
key: WobbleDeviation
summary: How far a hovering jumpjet unit drifts above and below its flight level.
see_also: [WobblesPerSecond, CruiseHeight, Climb]
when_omitted:
  kind: value
  value: "40"
---

`WobbleDeviation` sets how far a flying jumpjet bobs above and below its flight height, which is normally [`CruiseHeight`](/keys/cruiseheight/). The value is in leptons, 256 to a cell. The height it aims for rises to its flight height plus this value and falls to its flight height minus this value, following a smooth wave. [`WobblesPerSecond`](/keys/wobblespersecond/) sets how fast the wave cycles. The jumpjet chases that target at [`Climb`](/keys/climb/) leptons a frame, so a wave that moves faster than `Climb` is followed only partway.

```ini title="rules.ini"
[JumpjetControls]
WobbleDeviation=40
```

Only a jumpjet that is hovering or cruising bobs. The bobbing starts when the jumpjet reaches its flight height after taking off, and stops when it begins to descend.

The bobbing can also cost ground speed. While a jumpjet is short of the cell it is heading for, its speed drops by a tenth each frame it flies below half its target height, and by another tenth below a quarter. The target includes the bob. With a deviation that is large next to the flight height, the target can rise faster than the jumpjet climbs, leaving it below half the target and slowing it.
