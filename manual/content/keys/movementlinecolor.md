---
key: MovementLineColor
summary: The color of the movement line, as red, green and blue from 0 to 255.
see_also: ["system:action-lines", MovementLineDropShadowColor, TargetLineColor, NavComQueueLineColor]
when_omitted:
  kind: value
  value: "0,170,0"
---

The color applies to the movement line and to the squares on its ends. The movement line runs from a selected object to the end of its route. [Action lines](/systems/action-lines/) covers when it is drawn.

Write three numbers separated by commas. A value that does not begin with three such numbers keeps the default, and anything after the third number is ignored. A number outside 0 to 255 wraps around, so `300,0,0` is read as `44,0,0`.

```ini title="UI.INI"
[Ingame]
MovementLineColor=0,255,0
```
