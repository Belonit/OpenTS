---
key: IceGrowthRate
summary: Minutes between passes of the ice sheet creeping out across open water.
see_also: [IceSolidifyFrameTime, IceGrowthEnabled, IceCrackingWeight]
when_omitted:
  kind: value
  value: "1"
---

```ini title="rules.ini"
[AudioVisual]
IceGrowthRate=1.5
```

Ice sheets grow by one step each time this delay runs out. The delay is counted in game frames at 900 to the minute, and any fraction of a frame is dropped. The stock `1.5` therefore waits 1350 frames between steps. The first step runs when the scenario starts. At `0` ice never grows.

Growth needs a theater whose [`IsIceGrowthEnabled`](/keys/isicegrowthenabled/) is `yes`. It stops while [`IceGrowthEnabled`](/keys/icegrowthenabled/) is off, whether the map sets it to `no` or a trigger turns it off.

Each step turns ice-edge pieces into full ice, but only in cells that the map data marks as allowing ice growth. The mark belongs to the cell, not to its tile. Open water next to a grown cell then gets edge pieces of its own, so the sheet spreads one cell outward per step. Edge pieces from the [`Ice3Set`](/keys/ice3set/) tile set never grow, and neither does the last edge piece of each set.

This rate paces growth only. Cracked ice refreezes on the schedule that [`IceSolidifyFrameTime`](/keys/icesolidifyframetime/) sets.

:::caution[A tiny or negative rate grows ice every frame]
A value below about `0.0011` rounds to a delay of zero frames, and a negative value counts as no delay at all. Either one runs a growth step on every frame, and each step scans the whole map.
:::
