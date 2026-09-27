---
key: NavComQueueLineColor
summary: The color of the queued-destination lines, as red, green and blue from 0 to 255.
see_also: ["system:action-lines", ShowNavComQueueLines, NavComQueueLineDropShadowColor, MovementLineColor]
when_omitted:
  kind: value
  value: "74,77,255"
---

The color applies to the queue lines and to the squares on their ends. The queue lines run from the end of a selected object's movement line through its queued destinations. [Action lines](/systems/action-lines/) covers when they are drawn.

Write three numbers separated by commas. A value that does not begin with three such numbers keeps the default, and anything after the third number is ignored. A number outside 0 to 255 wraps around, so `300,0,0` is read as `44,0,0`.

```ini title="UI.INI"
[Ingame]
NavComQueueLineColor=0,200,255
```
