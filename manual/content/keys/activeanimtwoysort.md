---
key: ActiveAnimTwoYSort
summary: The sorting bias applied to the second active slot's animation, in leptons.
see_also: ["ActiveAnimTwo", "ActiveAnimTwoZAdjust"]
when_omitted:
  kind: value
  value: "0"
---

`ActiveAnimTwoYSort` moves the [`ActiveAnimTwo`](/keys/activeanimtwo/) animation in the drawing order of the ground layer, measured in leptons. A [cell](/glossary/#cell) is 256 leptons. A positive value moves the animation later in the order, so it is drawn after more of the objects around it. A negative value moves it earlier.

The value has no effect on an AnimType left at [`Surface=no`](/keys/surface/), because that animation is drawn in the air layer, which is not sorted.

The slot's value replaces the AnimType's [`YSortAdjust`](/keys/ysortadjust/). To keep that bias, repeat it in `ActiveAnimTwoYSort`.

Keep the value between -128 and 127, about half a cell either way. [Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers what happens outside that range.
