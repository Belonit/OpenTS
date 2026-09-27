---
key: MovementLineDashed
summary: Draws the movement line as dashes rather than a solid line.
see_also: ["system:action-lines", MovementLineColor, MovementLineThick]
when_omitted:
  kind: value
  value: "no"
---

Dashes are four pixels on and four off. They move along the line at one pixel every 128 milliseconds, a pace set by the clock, so it does not change with the game speed.

The movement line runs from a selected object to the end of its route. [Action lines](/systems/action-lines/) covers when it is drawn.
