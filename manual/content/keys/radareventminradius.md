---
key: RadarEventMinRadius
summary: Pixels of the radar pane a shrinking radar event box stops at.
see_also: ["system:map-visibility", RadarEventSpeed]
when_omitted:
  kind: value
  value: "5"
---

A [radar event](/reference/enums/radar-event/)'s box shrinks until the distance from the flagged cell to its corners reaches this many radar pixels. The settled marker keeps that size for the rest of its life. Its diagonal is twice this value, so at the default of `5` each side of the settled box is about 7 pixels long.

The box can settle only after it has shrunk to this size, and [`RadarEventSpeed`](/keys/radareventspeed/) sets how long that takes. A value at or above the distance the box opens at is reached on the first redraw. With a positive [`RadarEventRotationSpeed`](/keys/radareventrotationspeed/), the box then settles at once, with a diagonal at least as long as the pane's longer side.

Keep the value at `2` or more. At `0` or `1` the settled marker shrinks to a single pixel.
