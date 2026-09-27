---
key: IceCrackingWeight
summary: Vehicle weight at or above which crossing ice cracks it.
see_also: [IceBreakingWeight, Weight, IceCrackSounds, IceSolidifyFrameTime]
when_omitted:
  kind: value
  value: "2"
---

A vehicle whose [`Weight`](/keys/weight/) is at or above this value, but below [`IceBreakingWeight`](/keys/icebreakingweight/), cracks the ice it drives onto. The breaking test comes first, so if this value is at or above the breaking weight, no vehicle cracks ice.

The test runs each time a vehicle finishes entering a cell, and only in a theater whose [`IsIceGrowthEnabled`](/keys/isicegrowthenabled/) is `yes`. Infantry and aircraft never crack ice. A vehicle on a bridge over the ice is exempt.

Only full ice cracks. Ice-edge pieces along open water, and cells without ice, are left alone. A cracked cell gets the cracked tile of a randomly chosen ice set, and the ice around it is redrawn to match. Cracking plays one of [`IceCrackSounds`](/keys/icecracksounds/), and the cell is due to refreeze [`IceSolidifyFrameTime`](/keys/icesolidifyframetime/) frames later. The vehicle drives on unharmed.

A vehicle in this weight band that enters an already cracked cell breaks the ice and sinks, provided the whole block can break, as [`IceBreakingWeight`](/keys/icebreakingweight/) describes.

An explosion from a warhead with [`Wall=yes`](/keys/wall/#scope-warheadtype) or [`Fire=yes`](/keys/fire/) cracks the ice in its cell, unless it explodes on a bridge. If that cell is already cracked, the explosion breaks it open.
