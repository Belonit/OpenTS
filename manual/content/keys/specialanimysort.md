---
key: SpecialAnimYSort
summary: The sorting bias applied to the first special slot's animation, in leptons.
see_also: ["SpecialAnim", "SpecialAnimZAdjust"]
when_omitted:
  kind: value
  value: "0"
---

The value is added to the [`SpecialAnim`](/keys/specialanim/) animation's sorting position in the ground layer, in leptons; a [cell](/glossary/#cell) is 256 leptons. A positive value draws the animation in front of objects it would otherwise sort behind, and a negative value draws it behind objects it would otherwise cover. The animation does not move on screen.

A slot's animation is drawn in the ground layer only if its AnimType sets [`Surface=yes`](/keys/surface/). Any other animation is never sorted, so the value has no effect on it; [`SpecialAnimZAdjust`](/keys/specialanimzadjust/) changes what it is drawn over instead.

The value replaces the AnimType's own [`YSortAdjust=`](/keys/ysortadjust/). To keep that bias, repeat it here.

Keep the value between -128 and 127. It is stored in one signed byte, so a value outside that range wraps around; [Placement and draw order](/systems/building-animations/#placement-and-draw-order) gives an example.

The slot's animation names come from a different art entry when the structure sets [`Image=`](/keys/image/); [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) covers the split.
