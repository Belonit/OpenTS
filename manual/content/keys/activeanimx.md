---
key: ActiveAnimX
summary: How far right of the structure's drawing point the first active slot's animation sits, in screen pixels.
see_also: ["ActiveAnim", "ActiveAnimY"]
when_omitted:
  kind: value
  value: "0"
---

`ActiveAnimX` moves the [`ActiveAnim`](/keys/activeanim/) animation right of the structure's drawing point by that many screen pixels. A negative value moves it left.

[Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers how the offset differs from the slot's two draw-order biases.
