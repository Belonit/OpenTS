---
key: RandomLoopDelay
summary: The bounds, in game frames, of the pause inserted between one pass of a looping animation and the next.
see_also: ["LoopCount", "RandomRate", "Rate", "Report"]
when_omitted:
  kind: value
  value: "0,0"
---

Each time a looping animation finishes a pass and starts the next, it pauses for a random number of game frames between the two bounds. The bounds may be written in either order. Fifteen game frames make one second of game time, so `RandomLoopDelay=10,300` pauses for between two thirds of a second and twenty seconds.

The pause comes only between passes, so the animation needs more than one pass, normally a [`LoopCount`](/keys/loopcount/) above `1`. With both bounds at `0`, the animation loops without a pause.

While paused, the animation does not advance and is not drawn.

When the pause ends, the animation repeats the effects it had when it first started:

- Its [`Report=`](/keys/report/#scope-animtype) sound plays again.
- A [`TiberiumChainReaction=yes`](/keys/tiberiumchainreaction/) animation sets off the Tiberium beneath it again.
- If its largest frame is frame 0 of its shape, its [`Scorch`](/keys/scorch/), [`Crater`](/keys/crater/#scope-animtype) and [`Flamer`](/keys/flamer/) effects run again. A new scorch mark or crater appears only on a cell with no smudge yet, so a stationary animation leaves one mark.

Animations placed by the Play Anim At and Drop Zone Flare trigger actions skip the sound and the chain reaction.

A pass followed by no pause, including a pick of `0`, repeats none of these effects. A pause is therefore how a looping animation plays its sound once per pass.

:::caution[Keep both bounds at 0 or above]
A negative pause never runs out. An animation that picks one stops, is no longer drawn, and never finishes.
:::

Write both numbers. A value with only one number is ignored.
