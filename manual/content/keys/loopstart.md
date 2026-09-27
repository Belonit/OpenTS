---
key: LoopStart
summary: The frame a looping animation returns to at the start of each new pass.
see_also: ["LoopEnd", "LoopCount", "Start", "Reverse"]
when_omitted:
  kind: value
  value: "0"
---

The value is a frame number in the shape, not a count from [`Start`](/keys/start/). Every pass after the first restarts on this frame. The first pass always starts on `Start`, so the setting has an effect only when the animation plays more than one pass; see [`LoopCount`](/keys/loopcount/).

```ini title="art.ini"
[MYANIM] ; an animation of a 60-frame shape
Start=10
End=50      ; 50 stages from frame 10 end on frame 59
LoopStart=20
LoopCount=3
```

This animation plays frames 10 to 59 on its first pass, then 20 to 59 on each of the other two.

A [`Reverse=yes`](/keys/reverse/) animation ignores the setting. Each reversed pass restarts at [`LoopEnd`](/keys/loopend/) and steps backward.

The value is not checked against the shape or the other settings. A `LoopStart` below `Start` still restarts on exactly that frame. A `LoopStart` at or past `LoopEnd` makes each pass after the first, except the last, show only the `LoopStart` frame for one frame delay before it ends.
