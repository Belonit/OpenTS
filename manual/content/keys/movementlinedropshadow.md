---
key: MovementLineDropShadow
summary: Draws a shadow below the movement line.
see_also: ["system:action-lines", MovementLineDropShadowColor, MovementLineThick]
when_omitted:
  kind: value
  value: "no"
---

The shadow is a copy of the line directly beneath it, in [`MovementLineDropShadowColor`](/keys/movementlinedropshadowcolor/). It is one row high, or two rows under a [thick](/keys/movementlinethick/) line. Each end square gets a border in the shadow color, one pixel wide on a normal line and two on a thick one. On a thick line the shadow also shrinks the end squares from four pixels to three.

The movement line runs from a selected object to the end of its route. [Action lines](/systems/action-lines/) covers when it is drawn.
