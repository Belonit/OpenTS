---
key: ProductionAnimYSort
summary: The sorting bias applied to the production animation, in leptons.
see_also: ["ProductionAnim", "ProductionAnimZAdjust"]
when_omitted:
  kind: value
  value: "0"
---

`ProductionAnimYSort=` moves the production animation earlier or later in the drawing order of the objects on its layer, in leptons. It has an effect only when the animation's AnimType sets [`Surface=yes`](/keys/surface/); an animation in the default air layer is never sorted. [Placement and draw order](/systems/building-animations/#placement-and-draw-order) covers how it differs from the depth bias, why it replaces the AnimType's own sort bias, and why the value must stay between -128 and 127.
