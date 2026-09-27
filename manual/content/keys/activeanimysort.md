---
key: ActiveAnimYSort
summary: The sorting bias applied to the first active slot's animation, in leptons.
see_also: ["ActiveAnim", "ActiveAnimZAdjust"]
when_omitted:
  kind: value
  value: "0"
---

The value moves active slot one's animation within the draw order of the ground layer, in leptons; a [cell](/glossary/#cell) is 256 leptons. A larger value sorts the animation later among the objects around it, and a smaller value sorts it earlier. An AnimType left at [`Surface=no`](/keys/surface/) is drawn in the air layer, which is not sorted, so the value has no effect on it.

The value replaces the AnimType's own [`YSortAdjust`](/keys/ysortadjust/). It is read only when the slot has an animation name from [`ActiveAnim`](/keys/activeanim/) or [`ActiveAnimDamaged`](/keys/activeanimdamaged/).

Keep the value between -128 and 127. A value outside that range wraps around. [Placement and draw order](/systems/building-animations/#placement-and-draw-order) compares this bias with [`ActiveAnimZAdjust`](/keys/activeanimzadjust/).
