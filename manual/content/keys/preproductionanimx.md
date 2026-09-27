---
key: PreProductionAnimX
summary: How far right of the structure's drawing point the pre-production animation sits, in screen pixels.
see_also: ["PreProductionAnim", "PreProductionAnimY"]
when_omitted:
  kind: value
  value: "0"
---

A positive value moves the [`PreProductionAnim`](/keys/preproductionanim/) animation right of the point the structure is drawn at, and a negative value moves it left. The offset is measured on the structure's artwork, not on the map grid, so the animation keeps its place on the artwork wherever the structure stands.

[Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers how the offset differs from the two draw-order biases, and [Where the settings are read](/keys/productionanim/#where-the-settings-are-read) covers which art entry the X and Y offsets are read from.
