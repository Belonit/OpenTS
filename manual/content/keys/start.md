---
key: Start
summary: The frame of the shape the animation's first stage displays.
see_also: ["End", "LoopStart", "LoopEnd", "Reverse", "Next"]
when_omitted:
  kind: value
  value: "0"
---

The frame drawn is always `Start` plus the animation's current stage. The first stage is `0`, except for the reversed and chained animations described below. The animation therefore uses a run of frames beginning at `Start`. Several animations can share one shape file this way, each using a different run of it.

The value is not checked against the shape file. If `Start` is at or past the shape's frame count, the animation draws nothing for as long as it plays.

## What is counted from here and what is not

[`End`](/keys/end/) is a number of stages counted from `Start`, so a single pass shows frames `Start` through `Start + End - 1`. [`LoopStart`](/keys/loopstart/) and [`LoopEnd`](/keys/loopend/) are frame numbers in the shape file, not stage numbers. Set `End` and the loop range so that they describe the same run of frames.

```ini title="art.ini"
[MYPLUG_D] ; the damaged form of an animation sharing MYPLUG's shape
Image=MYPLUG
Start=10      ; the damaged sequence begins at frame 10
LoopStart=10  ; a frame number, not a count
LoopEnd=20    ; ends each pass on frame 20, which is not displayed
End=10        ; ten stages, so the final pass also covers frames 10 through 19
LoopCount=3
```

If `End` is omitted, the animation has as many stages as the shape file has frames, not as many as remain after `Start`. Without `End=10`, the final pass of the example would start at frame 10 and run 10 frames past the end of the shape.

:::caution[Reverse, ping-pong and chained animations add Start to a frame number]
Three cases use a frame number where a stage belongs, so the animation acts on the frame `Start` past the one set. In the example above, twice `Start` is frame 20.

- A [`Reverse=yes`](/keys/reverse/) animation begins each pass on frame `Start + LoopEnd`. On a single pass, it ends on reaching the frame at twice `Start`, which is not displayed. Given more than one pass, it holds frame `Start + LoopEnd` until its final pass. Keep `Start=0` on a reversed animation.
- A [`PingPong=yes`](/keys/pingpong/) animation given more than one pass turns only once. It climbs to frame `LoopEnd` or to the frame at twice `Start`, whichever comes first. It then plays downward through frame `0`, draws nothing after that, and never finishes. Keep `Start=0` on a ping-pong animation.
- An animation that switches to this type through [`Next`](/keys/next/) begins on the frame at twice its `Start`.
:::

The moment an animation leaves its scorch mark or crater is tied to the largest frame in the shape file, not to a stage, so `Start` does not move it. [`Crater`](/keys/crater/#scope-animtype) covers that timing.
