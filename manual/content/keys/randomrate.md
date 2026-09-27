---
key: RandomRate
summary: The pair of playback rates a new animation picks its frame delay from.
see_also: ["Rate", "Normalized", "RandomLoopDelay"]
when_omitted:
  kind: value
  value: "0,0"
  note: Both waits are zero, so the type uses its flat Rate.
---

`RandomRate` gives each animation of the type its own playback speed, picked at random between two rates. When set, it replaces the flat [`Rate=`](/keys/rate/#scope-animtype).

Both numbers are rates in animation frames per minute of game time, as for `Rate=`. Each is converted the same way, to a wait between frames of `900` divided by the rate, rounded down to whole game frames. A new animation picks a whole-frame wait between the two converted waits. An animation that changes into the type through [`Next=`](/keys/next/) picks again.

If both waits come out at `0`, the type uses its flat `Rate=` instead.

:::caution[Write the faster rate first]
The first number must give the shorter wait, so it must be the higher rate. If the first number gives a longer wait than the second, every animation of the type uses the second number's wait, with no randomness. `RandomRate=600,220` picks a wait of one to four frames. `RandomRate=220,600` describes the same span in the other order and always waits one frame.
:::

:::caution[Keep both rates between 1 and 900]
A rate of `0` or below, or one above `900`, converts to a wait of `0`. When only the second number does, the random rate is switched off and the type uses `Rate=`. When only the first number does, `0` stays in the pick. An animation that picks it stays on the frame it starts on and never finishes on its own.
:::

Write both numbers. A value with only one number is ignored.

[`Normalized=yes`](/keys/normalized/#scope-animtype) rescales the picked wait for the game speed.
