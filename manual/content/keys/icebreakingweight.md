---
key: IceBreakingWeight
summary: Vehicle weight at or above which crossing ice breaks it open into water.
see_also: [IceCrackingWeight, Weight, IceCrackSounds]
when_omitted:
  kind: value
  value: "4"
---

```ini title="rules.ini"
[General]
IceBreakingWeight=6

[MYHVYTNK]  ; synthetic UnitType
Weight=6    ; equal to the threshold, so it breaks the ice
```

A vehicle whose [`Weight`](/keys/weight/) is at or above this value breaks the ice it drives onto. The test runs each time a vehicle finishes entering a cell, and only in a theater whose [`IsIceGrowthEnabled`](/keys/isicegrowthenabled/) is `yes`. Infantry and aircraft never break ice, however heavy. A vehicle on a bridge over the ice is exempt.

The vehicle's weight is tested in this order:

1. At or above this value, the vehicle breaks the ice.
2. Otherwise, at or above [`IceCrackingWeight`](/keys/icecrackingweight/), the vehicle cracks the ice.
3. Otherwise, the ice is left alone.

Breaking affects a two-by-two block of cells: the cell the vehicle is in and three neighbors roughly in the direction it faces. If any cell of the block holds neither ice nor open water, nothing happens and the vehicle drives on. Otherwise all four cells become open water, and the ice around them is redrawn to match.

Objects on the block are affected by type:

- Vehicles start sinking and are stunned, unless their [movement zone](/reference/enums/movement-zone/) is `Amphibious`, `AmphibiousCrusher` or `AmphibiousDestroyer`.
- Infantry and aircraft are removed. Each one fires the destroyed events of any trigger attached to it.

Every object that sinks or is removed leaves a [`Wake`](/keys/wake/) animation.

:::caution[The vehicle that breaks the ice always sinks]
The vehicle whose arrival broke the ice starts sinking and is stunned even when its movement zone is amphibious. Open water counts as breakable, so a heavy amphibious vehicle also sinks when it drives across open water in a theater with ice.
:::
