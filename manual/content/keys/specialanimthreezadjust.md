---
key: SpecialAnimThreeZAdjust
summary: The depth bias applied to the third special slot's animation.
see_also: ["SpecialAnimThree", "SpecialAnimThreeYSort", "SpecialAnim"]
when_omitted:
  kind: value
  value: "0"
---

A negative value brings the [`SpecialAnimThree`](/keys/specialanimthree/) animation toward the viewer, so it is drawn over the structure and anything else at that depth. A positive value pushes it back, so the structure covers it.

Keep the value between -128 and 127. It is stored in one signed byte, so a value outside that range wraps around; [Placement and draw order](/systems/building-animations/#placement-and-draw-order) gives an example.

The slot's animation names come from a different art entry when the structure sets [`Image=`](/keys/image/); [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) covers the split.
