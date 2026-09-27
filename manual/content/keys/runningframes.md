---
key: RunningFrames
summary: The number of frames each of the eight facings of a burning victim's run cycle occupies.
see_also: ["IsFlamingGuy", "Start", "Rate"]
when_omitted:
  kind: value
  value: "0"
---

`RunningFrames=` sets how many frames each facing of a burning victim's run cycle uses. Only an [`IsFlamingGuy=yes`](/keys/isflamingguy/) animation reads it.

The run cycle is eight consecutive blocks of this many frames, one block per facing, starting at the animation's [`Start`](/keys/start/) frame. The victim shows the block for the direction he is running. Within the block, the frame advances once every three game frames and wraps around.

When the run ends, the death sequence begins at frame eight times `RunningFrames` plus one, counted from `Start`. The frame right after the run cycle is skipped. The sequence ends on frame half the shape's frame count minus one, also counted from `Start`. With `Start=0`, that is the last frame of the shape's first half.

The second half of the shape holds shadow frames. Each drawn frame is paired with the frame half the shape's frame count later, which is drawn darkened beneath the victim. The shadow is not drawn while he falls.

The game does not check the run cycle against the artwork. A value too large for the shape makes the victim run on frames that draw nothing.

:::danger[Set RunningFrames on every burning victim animation]
An `IsFlamingGuy=yes` animation with `RunningFrames=0`, the default, divides by zero and crashes the game as soon as the victim starts to run. A victim created with nowhere to run goes straight to its death sequence and does not crash.
:::
