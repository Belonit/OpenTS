---
key: Rate
scope: animtype
label: Playback rate
when_omitted:
  kind: value
  value: "900"
  note: The wait is one game frame, so the animation advances every game frame.
---

`Rate=` sets the animation's playback speed in animation frames per minute of game time. The game converts it to a wait between frames of `900` divided by the rate, rounded down to whole game frames. `Rate=900` advances one frame every game frame, and `Rate=450` one frame every second game frame.

Because the wait is rounded down, a rate that does not divide `900` evenly plays faster than written. `Rate=200` waits four game frames, which plays at 225 frames per minute.

:::caution[Keep Rate between 1 and 900]
A rate of `0` or below, or one above `900`, gives a wait of `0`. An animation with a wait of `0` stays on the frame it starts on and never finishes on its own. `Rate=-1` is the exception: it counts as no setting at all.
:::

[`RandomRate`](/keys/randomrate/), when set, replaces this rate with a random one. [`Normalized=yes`](/keys/normalized/#scope-animtype) rescales the wait for the game speed.
