---
key: ActiveAnimY
summary: How far below the structure's drawing point the first active slot's animation sits, in screen pixels.
see_also: ["ActiveAnim", "ActiveAnimX"]
when_omitted:
  kind: value
  value: "0"
---

`ActiveAnimY` moves the [`ActiveAnim`](/keys/activeanim/) animation down from the structure's drawing point by that many screen pixels. A negative value lifts it above that point.

[Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers how the offset differs from the slot's two draw-order biases.
