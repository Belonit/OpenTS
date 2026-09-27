---
key: MovementLineThick
summary: Draws the movement line two rows high.
see_also: ["system:action-lines", MovementLineDashed, MovementLineDropShadow]
when_omitted:
  kind: value
  value: "no"
---

A second copy of the line is drawn one row below the first. The squares at the line's ends grow from three pixels to four, or stay at three when [`MovementLineDropShadow=yes`](/keys/movementlinedropshadow/) gives them a border.

The movement line runs from a selected object to the end of its route. [Action lines](/systems/action-lines/) covers when it is drawn.
