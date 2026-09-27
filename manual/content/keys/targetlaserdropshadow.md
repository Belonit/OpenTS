---
key: TargetLaserDropShadow
summary: Draws a shadow below the sighting laser.
see_also: ["system:action-lines", TargetLaser, TargetLaserDropShadowColor, TargetLaserThick]
when_omitted:
  kind: value
  value: "no"
---

The shadow is a copy of the laser directly beneath it, in [`TargetLaserDropShadowColor`](/keys/targetlaserdropshadowcolor/). It is one row high, or two rows under a [thick](/keys/targetlaserthick/) laser. Each end square gets a border in the shadow color, one pixel wide on a normal laser and two on a thick one. On a thick laser the shadow also shrinks the end squares from four pixels to three.

The sighting laser is the line a firing vehicle with [`TargetLaser=yes`](/keys/targetlaser/) draws to where its shot is aimed. [Action lines](/systems/action-lines/) covers when it is drawn.
