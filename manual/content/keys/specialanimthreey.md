---
key: SpecialAnimThreeY
summary: How far below the structure's drawing point the third special slot's animation sits, in screen pixels.
see_also: ["SpecialAnimThree", "SpecialAnimThreeX", "SpecialAnim"]
when_omitted:
  kind: value
  value: "0"
---

`SpecialAnimThreeY` moves the [`SpecialAnimThree`](/keys/specialanimthree/) animation down from the structure's drawing point by that many screen pixels. A negative value moves it up. The offset pins the animation to a point on the artwork, so it stays in place wherever the structure stands.

The value is read only when the slot has an animation name from `SpecialAnimThree` or [`SpecialAnimThreeDamaged`](/keys/specialanimthreedamaged/). Write it in the art entry named after the structure's ObjectType ID, even when [`Image=`](/keys/image/) puts the animation names in another entry. [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) has the full table. [Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers how the offset differs from the slot's two draw-order biases.
