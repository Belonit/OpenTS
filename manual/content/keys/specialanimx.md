---
key: SpecialAnimX
summary: How far right of the structure's drawing point the first special slot's animation sits, in screen pixels.
see_also: ["SpecialAnim", "SpecialAnimY"]
when_omitted:
  kind: value
  value: "0"
---

A positive value moves the [`SpecialAnim`](/keys/specialanim/) animation right of the structure's drawing point, and a negative value moves it left. [`SpecialAnimY`](/keys/specialanimy/) is the vertical half of the same offset. The offset is measured on the structure's artwork, not from a cell, so the animation keeps its place on the structure wherever the structure stands.

The offset moves where the animation is drawn. [`SpecialAnimZAdjust`](/keys/specialanimzadjust/) and [`SpecialAnimYSort`](/keys/specialanimysort/) change only what it is drawn over.

The slot's animation names come from a different art entry when the structure sets [`Image=`](/keys/image/); [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) covers the split.
