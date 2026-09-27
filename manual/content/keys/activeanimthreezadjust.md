---
key: ActiveAnimThreeZAdjust
summary: The depth bias applied to the third active slot's animation.
see_also: ["ActiveAnimThree", "ActiveAnimThreeYSort"]
when_omitted:
  kind: value
  value: "0"
---

`ActiveAnimThreeZAdjust` shifts the depth at which the [`ActiveAnimThree`](/keys/activeanimthree/) animation is drawn. A negative value brings the animation toward the viewer, and a large enough value draws it over the structure. A positive value pushes it back, and a large enough value lets the structure cover it.

Keep the value between -128 and 127. [Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers what happens outside that range and how the depth bias differs from the sorting bias.
