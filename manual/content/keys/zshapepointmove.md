---
key: ZShapePointMove
summary: Moves the shared depth shape stamped under a structure, in screen pixels.
see_also: ["NormalZAdjust", "Foundation"]
when_omitted:
  kind: value
  value: "0,0"
---

Structures are drawn with a shared depth shape, `BUILDNGZ.SHP`, which sets the depth other objects sort against. The engine reads that shape from a fixed point, adjusted for the structure's [`Foundation`](/keys/foundation/). `ZShapePointMove` moves that reading point by a pair of screen-pixel offsets. The structure's artwork does not move.

The first number moves the reading point right and the second moves it down. The depth pattern under the structure therefore moves the opposite way: left for a positive first number, up for a positive second number.

```ini title="art.ini"
[MYREFN] ; the refinery's Image entry in art.ini
Foundation=4x3
ZShapePointMove=24,-12
```

The offset has no effect while a structure is drawn without the depth shape, which includes these cases:

- The structure is six or more cells wide. The [`6x4`](/keys/foundation/#the-irregular-sizes) footprint is the only one that wide.
- The structure is a [`Gate=yes`](/keys/gate/) structure and its gate is opening, open or closing.
- The structure is a firestorm wall segment.

The width limit does not apply to a fogged structure. A `6x4` structure therefore uses the depth shape, and this offset, while it is fogged.

A value that does not begin with two whole numbers separated by a comma, such as a single `24`, is ignored as a whole. Neither number is applied on its own. Text after the second number is dropped, so `24,-12,5` reads as `24,-12`.
