---
key: ProductionAnimY
summary: How far below the structure's drawing point the production animation sits, in screen pixels.
see_also: ["ProductionAnim", "ProductionAnimX"]
when_omitted:
  kind: value
  value: "0"
---

`ProductionAnimY=` moves the [`ProductionAnim`](/keys/productionanim/) animation down from the structure's drawing point, in screen pixels. A negative value moves it up. The offset is fixed to the structure's artwork, not to a cell, so it is the same wherever the structure stands.

[Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers how the offset differs from the two draw-order biases, and [Where the settings are read](/keys/productionanim/#where-the-settings-are-read) covers which art entry the offset comes from.
