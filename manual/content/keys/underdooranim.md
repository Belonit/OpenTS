---
key: UnderDoorAnim
summary: The shape drawn beneath a structure's factory door while it unloads.
see_also: ["DoorAnim", "DoorStages", "DeployingAnim", "WeaponsFactory"]
when_omitted:
  kind: value
  value: ""
  note: No under-door shape is loaded and none is drawn.
---

`UnderDoorAnim` names a shape that a structure draws while it is unloading, such as a war factory letting a finished vehicle out. Write the filename without its extension; the engine loads `<value>.SHP`. The name gets the same theater letter rewrite that [`DoorAnim`](/keys/dooranim/) describes.

The shape is drawn after the structure and its [`BibShape`](/keys/bibshape/), at ground depth. Only its first two frames are used, chosen by the structure's health alone:

| Structure's health | Frame drawn |
| --- | --- |
| Above [`ConditionYellow`](/keys/conditionyellow/) | `0` |
| At or below `ConditionYellow` | `1` |

[`DoorStages`](/keys/doorstages/) does not apply to this shape.

The shape is lit like the structure, including its [`ExtraLight`](/keys/extralight/). The `DoorAnim` frames, by contrast, ignore `ExtraLight`.
