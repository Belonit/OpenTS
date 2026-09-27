---
key: NavComQueueLineDashed
summary: Draws the queued-destination lines as dashes rather than solid lines.
see_also: ["system:action-lines", ShowNavComQueueLines, NavComQueueLineColor, NavComQueueLineThick]
when_omitted:
  kind: value
  value: "no"
---

Dashes are four pixels on and four off. They move along each line at one pixel every 128 milliseconds, a pace set by the clock, so it does not change with the game speed.

The queue lines run from the end of a selected object's movement line through its queued destinations. [Action lines](/systems/action-lines/) covers when they are drawn.
