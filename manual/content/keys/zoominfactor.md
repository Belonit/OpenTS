---
key: ZoomInFactor
summary: How far the tactical view magnifies when a trigger zooms it in.
when_omitted:
  kind: value
  value: "2"
---

`ZoomInFactor` is the magnification the [Zoom in](/mapping/actions/taction-zoom-in/) trigger action applies. While zoomed, the game enlarges the center of the screen area beside the sidebar to fill that area. The part shown is a rectangle whose width and height are that area's width and height divided by this value. The sidebar is not magnified. At `2`, the view shows a quarter of the usual area at twice the size. [Zoom out](/mapping/actions/taction-zoom-out/) returns the view to normal size.

At `1`, Zoom in leaves the picture unchanged, but its other effects on the cursor, input and timing still apply. That action's page lists them.

Keep the value at `1` or above. A value below `1` asks for a rectangle larger than the area it is taken from, and at `0` or below the rectangle has no usable size.

The [Change Zoom Level...](/mapping/actions/taction-change-zoom/) trigger action does not read this value and changes nothing.
