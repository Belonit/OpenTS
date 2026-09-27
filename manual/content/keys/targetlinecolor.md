---
key: TargetLineColor
summary: The color of the target line, as red, green and blue from 0 to 255.
see_also: ["system:action-lines", TargetLineDropShadowColor, MovementLineColor, TargetLaserColor]
when_omitted:
  kind: value
  value: "173,0,0"
---

The color applies to the target line and to the squares on its ends. The target line runs from a selected object's firing point to what it is attacking. [Action lines](/systems/action-lines/) covers when it is drawn.

Write three numbers separated by commas. A value that does not begin with three such numbers keeps the default, and anything after the third number is ignored. A number outside 0 to 255 wraps around, so `300,0,0` is read as `44,0,0`.

```ini title="UI.INI"
[Ingame]
TargetLineColor=255,64,64
```
