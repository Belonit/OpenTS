---
key: IceSolidifyFrameTime
summary: Frames a cracked ice cell waits before it freezes back to solid.
see_also: [IceGrowthRate, IceGrowthEnabled, IceCrackingWeight, IceBreakingWeight, IceCrackSounds]
when_omitted:
  kind: value
  value: "500"
  note: A little over 33 seconds at 15 frames to the second.
---

```ini title="rules.ini"
[AudioVisual]
IceSolidifyFrameTime=1000
```

A cracked ice cell freezes back to full ice this many frames after it cracked, on the first frame after the delay has passed. The game runs 15 frames a second, so the stock `1000` is a little over a minute.

When a cell refreezes, any cracked cell that shares a side with it refreezes at the same time, however long that cell has left to wait.

Until it refreezes, a cracked cell breaks under the next vehicle in the cracking band, as [`IceCrackingWeight`](/keys/icecrackingweight/) describes.

:::caution[Cracks heal only while the map allows ice growth]
Cracked ice does not refreeze while [`IceGrowthEnabled`](/keys/icegrowthenabled/) is off, whether the map sets it to `no` or a trigger turns it off. Cracking does not check that setting. With growth off, every crack stays until a trigger turns growth back on, and the next vehicle in the cracking band to cross a crack breaks through it. Cracks whose delay has already passed refreeze on the first frame after growth is turned back on.
:::
