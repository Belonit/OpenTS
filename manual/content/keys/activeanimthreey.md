---
key: ActiveAnimThreeY
summary: How far below the structure's drawing point the third active slot's animation sits, in screen pixels.
see_also: ["ActiveAnimThree", "ActiveAnimThreeX"]
when_omitted:
  kind: value
  value: "0"
---

`ActiveAnimThreeY` moves the [`ActiveAnimThree`](/keys/activeanimthree/) animation down from the structure's drawing point by that many screen pixels. A negative value lifts it above that point.

[Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers how the offset differs from the slot's two draw-order biases.
