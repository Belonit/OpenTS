---
key: TargetLineThick
summary: Draws the target line two rows high.
see_also: ["system:action-lines", TargetLineDashed, TargetLineDropShadow]
when_omitted:
  kind: value
  value: "no"
---

A second copy of the line is drawn one row below the first. The squares on the line's ends grow from three pixels wide to four. With [`TargetLineDropShadow=yes`](/keys/targetlinedropshadow/) also set, they stay three pixels wide.

The target line runs from a selected object's firing point to what it is attacking. [Action lines](/systems/action-lines/) covers when it is drawn.
