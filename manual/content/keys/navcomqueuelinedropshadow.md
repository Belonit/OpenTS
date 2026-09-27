---
key: NavComQueueLineDropShadow
summary: Draws a shadow below the queued-destination lines.
see_also: ["system:action-lines", ShowNavComQueueLines, NavComQueueLineDropShadowColor, NavComQueueLineThick]
when_omitted:
  kind: value
  value: "no"
---

The shadow is a copy of the line directly beneath it, in [`NavComQueueLineDropShadowColor`](/keys/navcomqueuelinedropshadowcolor/). It is one row high, or two rows under a [thick](/keys/navcomqueuelinethick/) line. Each end square gets a border in the shadow color, one pixel wide on a normal line and two on a thick one. On a thick line the shadow also shrinks the end squares from four pixels to three.

The queue lines run from the end of a selected object's movement line through its queued destinations. [Action lines](/systems/action-lines/) covers when they are drawn.
