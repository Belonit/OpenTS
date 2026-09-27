---
key: Normalized
scope: particletype
label: Particle state pacing
see_also: ["StateAIAdvance", "FinalDamageState"]
when_omitted:
  kind: value
  value: "no"
---

`Normalized=yes` paces a [`Fire`](/keys/behaveslike/#scope-particletype) particle's animation to the distance it is fired across, so flames fired at near and far targets both reach [`FinalDamageState`](/keys/finaldamagestate/) at roughly the end of their flight. The particle ignores [`StateAIAdvance`](/keys/stateaiadvance/) and works out its own interval, in frames per state, when it is created:

1. Divide the distance from its starting point to its target by its starting [`Velocity`](/keys/velocity/). This is its flight time in frames.
2. Divide the flight time by one more than `FinalDamageState`, add one, and drop the fraction.

For example, a flame with `Velocity=28` and `FinalDamageState=14` aimed 1,280 leptons away has a flight time of about 46 frames, which gives an interval of 4 frames per state.

The frame added in step 2 makes the sequence run somewhat longer than the flight, most noticeably for short flights. The calculation also ignores [`Deacc`](/keys/deacc/) and assumes the flame keeps its starting speed. A flame that slows down therefore covers less ground in each state, and reaches `FinalDamageState` closer to where it started.

Only `Fire` particles use the result. Particles of every other behavior step at `StateAIAdvance` as written.

The interval is held in one signed byte, like `StateAIAdvance`. A result above 127 wraps around to a smaller or negative interval, and one that lands on `0` or `-1` stops the game as `StateAIAdvance` describes.

:::caution[A target straight above or below gives an unrelated interval]
The flight time is worked out from the horizontal part of the particle's motion. When the target sits at the same horizontal position as the starting point, the flight time is taken as 9999 frames. After the division and the byte wrap, the interval that results depends only on `FinalDamageState`, not on the flight.
:::
