---
key: TargetLineDropShadow
summary: Draws a shadow below the target line.
see_also: ["system:action-lines", TargetLineDropShadowColor, TargetLineThick]
when_omitted:
  kind: value
  value: "no"
---

The shadow is a copy of the line in [`TargetLineDropShadowColor`](/keys/targetlinedropshadowcolor/), drawn directly below it. Under a [thick](/keys/targetlinethick/) line the shadow is two rows high as well.

Each end square gets a border in the shadow color, one pixel wide on a normal line and two on a thick one. On a thick line the shadow also shrinks the end squares from four pixels wide to three.

The target line runs from a selected object's firing point to what it is attacking. [Action lines](/systems/action-lines/) covers when it is drawn.
