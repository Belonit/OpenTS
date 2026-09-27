---
key: DamagedDoor
summary: Draws the factory door animation from a second block of frames once the structure is damaged.
see_also: ["DoorAnim", "DoorStages", "UnderDoorAnim"]
when_omitted:
  kind: value
  value: "no"
---

With the flag set, a structure at or below [`ConditionYellow`](/keys/conditionyellow/) draws its [`DoorAnim`](/keys/dooranim/) from the frames directly after the healthy ones. The door's frame number is limited to the healthy range first, and [`DoorStages`](/keys/doorstages/) is then added to it. The damaged frames therefore form a second block the same length as the healthy block.

The flag affects nothing else. [`UnderDoorAnim`](/keys/underdooranim/) switches to its damaged frame on the same health test whether or not this is set.
