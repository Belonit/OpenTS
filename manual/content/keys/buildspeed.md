---
key: BuildSpeed
summary: The multiplier that turns an object's cost into its base build time.
when_omitted:
  kind: value
  value: "1"
---

An object's base build time, in game frames, is its [`Cost`](/keys/cost/#scope-aircrafttype) times this value times 0.9 frames per credit. With `BuildSpeed=1`, a 1000-credit object gets a base time of 900 frames, one minute at 15 frames a second. The shipped `rules.ini` sets `.8`, which gives the same object 720 frames, or 48 seconds. [Production steps](/systems/production/#production-steps) then round the final build time down to whole steps and hold it within fixed limits. A typical build ends slightly shorter, but a very cheap object is lengthened to the minimum and a very expensive one is cut to the maximum.

The value scales every producible object type alike. A value of `2` doubles every base build time.

The other build-time factors apply to the base time afterwards, as [How long it takes](/systems/production/#how-long-it-takes) lists: the country and difficulty [`BuildTime`](/keys/buildtime/) multipliers, the [game-speed bias](/keys/gamespeedbias/), the [power](/systems/power/#production) divisor, the number of factories, and the [wall coefficient](/keys/wallbuildspeedcoefficient/).
