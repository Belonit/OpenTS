---
key: NavComQueueLineThick
summary: Draws the queued-destination lines two rows high.
see_also: ["system:action-lines", ShowNavComQueueLines, NavComQueueLineDashed, NavComQueueLineDropShadow]
when_omitted:
  kind: value
  value: "no"
---

A second copy of each line is drawn one row below the first. The squares at the lines' ends grow from three pixels to four, or stay at three when [`NavComQueueLineDropShadow=yes`](/keys/navcomqueuelinedropshadow/) gives them a border.

The queue lines run from the end of a selected object's movement line through its queued destinations. [Action lines](/systems/action-lines/) covers when they are drawn.
