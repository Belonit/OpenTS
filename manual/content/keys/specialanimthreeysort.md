---
key: SpecialAnimThreeYSort
summary: The sorting bias applied to the third special slot's animation, in leptons.
see_also: ["SpecialAnimThree", "SpecialAnimThreeZAdjust", "SpecialAnim"]
when_omitted:
  kind: value
  value: "0"
---

The value moves the third special slot's animation within the draw order of the ground layer, in leptons; a [cell](/glossary/#cell) is 256 leptons. A larger value sorts the animation later among the objects around it, and a smaller value sorts it earlier. An AnimType left at [`Surface=no`](/keys/surface/) is drawn in the air layer, which is not sorted, so the value has no effect on it.

The value replaces the AnimType's own [`YSortAdjust`](/keys/ysortadjust/). It is read only when the slot has an animation name from [`SpecialAnimThree`](/keys/specialanimthree/) or [`SpecialAnimThreeDamaged`](/keys/specialanimthreedamaged/). Write it in the art entry named after the structure's ObjectType ID, even when [`Image=`](/keys/image/) puts the animation names in another entry. [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) has the full table.

Keep the value between -128 and 127. A value outside that range wraps around. [Placement and draw order](/systems/building-animations/#placement-and-draw-order) compares this bias with [`SpecialAnimThreeZAdjust`](/keys/specialanimthreezadjust/).
