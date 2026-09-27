---
key: TargetLaserColor
summary: The color of the sighting laser, as red, green and blue from 0 to 255.
see_also: ["system:action-lines", TargetLaser, TargetLaserDropShadowColor, TargetLineColor]
when_omitted:
  kind: value
  value: "173,0,0"
---

The color applies to the sighting laser and to the squares on its ends. The sighting laser is the line a firing vehicle with [`TargetLaser=yes`](/keys/targetlaser/) draws to where its shot is aimed. [Action lines](/systems/action-lines/) covers when it is drawn.

Write three numbers separated by commas. A value that does not begin with three such numbers keeps the default, and anything after the third number is ignored. A number outside 0 to 255 wraps around, so `300,0,0` is read as `44,0,0`.

The target line a selected object draws to what it is attacking is a separate line. [`TargetLineColor`](/keys/targetlinecolor/) sets its color, and this key does not affect it.

```ini title="UI.INI"
[Ingame]
TargetLaserColor=255,0,0
```
