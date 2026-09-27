---
key: TargetLaserDropShadowColor
summary: The color of the shadow below the sighting laser, as red, green and blue from 0 to 255.
see_also: ["system:action-lines", TargetLaser, TargetLaserDropShadow, TargetLaserColor]
when_omitted:
  kind: value
  value: "0,0,0"
---

The color applies only with [`TargetLaserDropShadow=yes`](/keys/targetlaserdropshadow/). It colors the shadow below the laser and the border around each end square.

Write three numbers separated by commas. A value that does not begin with three such numbers keeps the default, and anything after the third number is ignored. A number outside 0 to 255 wraps around, so `300,0,0` is read as `44,0,0`.
