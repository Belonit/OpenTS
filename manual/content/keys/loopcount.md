---
key: LoopCount
summary: The number of passes an animation of the type makes before it ends or chains.
see_also: ["LoopStart", "LoopEnd", "End", "PingPong", "Next", "RandomLoopDelay"]
when_omitted:
  kind: value
  value: "0"
---

The game multiplies this setting by the number of passes it requests when it creates the animation. The result wraps into the range `0` to `255`, and a result of `0` then counts as `1`. Most animations are requested for one pass. Some are requested for several, such as the fires on a damaged building. `0` and `1` therefore both give a single pass when one is requested. When several are requested, `1` plays them all and `0` still plays one.

With one pass requested, the extremes behave as follows:

- `-1` loops until something else removes the animation, such as the structure it belongs to. `255` and `-257` do the same. When several passes are requested, `-1` is multiplied first and gives a finite count: 254 passes when two are requested.
- `256` acts like `0` and `257` like `1`, so both give a single pass. `-256` and `-255` also give a single pass.
- `-2` to `-254` give long finite counts: `LoopCount=-2` plays 254 passes.

```ini title="art.ini"
[MYREFN_C] ; an active animation for a refinery
Image=MYREFN_C
LoopStart=0
LoopEnd=16
LoopCount=-1  ; runs until the structure stops it
Rate=350
Surface=yes
```

With more than one pass, each pass plays a different stretch of frames:

1. The first pass starts on [`Start`](/keys/start/) and ends at [`LoopEnd`](/keys/loopend/).
2. Each middle pass starts on [`LoopStart`](/keys/loopstart/) and ends at `LoopEnd`.
3. The last pass starts on `LoopStart` and runs to the end of the stage count in [`End`](/keys/end/).

A [`PingPong=yes`](/keys/pingpong/) animation never uses up a pass. It reverses direction at each end instead of finishing, so the count never ends it. The count still decides where it turns:

- With a single pass, it turns at the end of the `End` stage count and at its first frame.
- With more than one pass and `Start=0`, it turns at `LoopEnd` and at its first frame.

:::caution[Give a multi-pass ping-pong animation Start=0]
With a nonzero [`Start`](/keys/start/) and more than one pass, a `PingPong=yes` animation turns only once, at the frame numbered twice `Start` or at `LoopEnd`, whichever it reaches first. It then steps backward without end, past the first frame of the shape. Set `Start=0`, or set `LoopCount=0` so the animation gets a single pass.
:::
