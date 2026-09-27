---
key: ActiveAnimZAdjust
summary: The depth bias applied to the first active slot's animation.
see_also: ["ActiveAnim", "ActiveAnimYSort"]
when_omitted:
  kind: value
  value: "0"
---

The value decides whether active slot one's animation is drawn over the structure or behind it. A negative value brings the animation toward the viewer, so it covers the structure. A positive value pushes it back, so the structure covers it.

The value is read only when the slot has an animation name from [`ActiveAnim`](/keys/activeanim/) or [`ActiveAnimDamaged`](/keys/activeanimdamaged/).

Keep the value between -128 and 127. A value outside that range wraps around: `ActiveAnimZAdjust=200` is stored as -56 and draws the animation in front of the structure. [Placement and draw order](/systems/building-animations/#placement-and-draw-order) compares this bias with [`ActiveAnimYSort`](/keys/activeanimysort/).
