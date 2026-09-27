---
key: TargetLineDashed
summary: Draws the target line as moving dashes.
see_also: ["system:action-lines", TargetLineColor, TargetLineThick]
when_omitted:
  kind: value
  value: "no"
---

The dashes are four pixels on and four off. They move along the line at one pixel every 64 milliseconds of real time, so their pace does not change with the game speed.

The target line runs from a selected object's firing point to what it is attacking. [Action lines](/systems/action-lines/) covers when it is drawn.
