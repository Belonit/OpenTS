---
key: SpecialAnimY
summary: How far below the structure's drawing point the first special slot's animation sits, in screen pixels.
see_also: ["SpecialAnim", "SpecialAnimX"]
when_omitted:
  kind: value
  value: "0"
---

A positive value moves the [`SpecialAnim`](/keys/specialanim/) animation down the screen from the structure's drawing point, and a negative value lifts it above that point. [`SpecialAnimX`](/keys/specialanimx/) is the horizontal half of the same offset. The offset is measured on the structure's artwork, not from a cell, so the animation keeps its place on the structure wherever the structure stands.

The offset moves where the animation is drawn. [`SpecialAnimZAdjust`](/keys/specialanimzadjust/) and [`SpecialAnimYSort`](/keys/specialanimysort/) change only what it is drawn over.

The slot's animation names come from a different art entry when the structure sets [`Image=`](/keys/image/); [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) covers the split.
