---
key: DeployingAnim
summary: The shape file that replaces a structure's own artwork while it unloads.
see_also: ["DoorAnim", "UnderDoorAnim", "NormalZAdjust", "WeaponsFactory"]
when_omitted:
  kind: value
  value: ""
  note: No deploying shape is loaded and the structure keeps its own artwork throughout.
---

The value is a filename without its extension, and an empty value is ignored. The game loads `<value>.SHP` with the rules. It rewrites the name for the theater and loads the file again on the same occasions as [`DoorAnim`](/keys/dooranim/).

While the structure is unloading, the game draws this file in place of the structure's main shape. That draw leaves out the type's [`NormalZAdjust`](/keys/normalzadjust/) depth bias. The frame is the one the structure would show from its own artwork.

Lay the file out like the main artwork, with the healthy frames first and the damaged frames after them. The frame drawn never goes past half the file's frame count, which is the first damaged frame. In a 20-frame file, frames `0` to `10` can be shown. The same limit applies to the main artwork when no deploying shape is in use.
