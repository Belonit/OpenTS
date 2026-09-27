---
key: ActiveAnimTwoZAdjust
summary: The depth bias applied to the second active slot's animation.
see_also: ["ActiveAnimTwo", "ActiveAnimTwoYSort"]
when_omitted:
  kind: value
  value: "0"
---

`ActiveAnimTwoZAdjust` shifts the depth at which the [`ActiveAnimTwo`](/keys/activeanimtwo/) animation is drawn. A negative value brings the animation toward the viewer, and a large enough value draws it over the structure. A positive value pushes it back, and a large enough value lets the structure cover it.

Keep the value between -128 and 127. [Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers what happens outside that range and how the depth bias differs from the sorting bias.
