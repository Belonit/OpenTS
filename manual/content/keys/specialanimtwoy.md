---
key: SpecialAnimTwoY
summary: How far below the structure's drawing point the second special slot's animation sits, in screen pixels.
see_also: ["SpecialAnimTwo", "SpecialAnimTwoX", "SpecialAnim"]
when_omitted:
  kind: value
  value: "0"
---

A positive value moves the [`SpecialAnimTwo`](/keys/specialanimtwo/) animation down the screen from the structure's drawing point, and a negative value lifts it above that point. [`SpecialAnimTwoX`](/keys/specialanimtwox/) is the horizontal half of the same offset. The offset is measured on the structure's artwork, not from a cell, so the animation keeps its place on the structure wherever the structure stands.

The offset moves where the animation is drawn. [`SpecialAnimTwoZAdjust`](/keys/specialanimtwozadjust/) and [`SpecialAnimTwoYSort`](/keys/specialanimtwoysort/) change only what it is drawn over.

The slot's animation names come from a different art entry when the structure sets [`Image=`](/keys/image/); [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) covers the split.
