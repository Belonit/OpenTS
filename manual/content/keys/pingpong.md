---
key: PingPong
summary: Reverses the animation's direction each time it reaches either end of its frames.
see_also: ["LoopCount", "LoopEnd", "End", "Reverse", "Start"]
when_omitted:
  kind: value
  value: "no"
---

A ping-pong animation turns around at each end of its range and plays back the way it came. It does not jump back to its first frame or finish.

The turning points depend on how many passes the animation has, which is normally its [`LoopCount`](/keys/loopcount/). The frame numbers below assume [`Start`](/keys/start/) is `0`, the usual case; that page explains how a non-zero `Start` shifts them.

| Passes | Turns at the top | Turns at the bottom |
| --- | --- | --- |
| One | Frame [`End`](/keys/end/) | Frame `0` |
| More than one | Frame [`LoopEnd`](/keys/loopend/) | Frame `0` |

The animation shows the top frame for one step before it turns back. By default `End` and `LoopEnd` equal the shape's frame count, which is one past its last frame. The top turning frame then draws nothing, so the animation blinks each time it turns at the top. To avoid the blink, set `End` or `LoopEnd` to the frame count minus one, the number of the last frame.

:::caution[A ping-pong animation never finishes on its own]
Turning at the top takes the place of finishing a pass. The animation never uses up a pass, never changes type through [`Next=`](/keys/next/), and never removes itself. It stays until something else removes it: its structure clears it, the object it is attached to is destroyed, or the scenario ends. A ping-pong animation placed on the map by itself lasts for the rest of the mission.

The one exception is a single-pass animation that also sets [`Reverse=yes`](/keys/reverse/) and a `Start` above `0`. It finishes on its way down, before it reaches the bottom turning point.
:::
