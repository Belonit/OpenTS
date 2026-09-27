---
key: SiloDamage
summary: Draws a fill level on a building that stores Tiberium.
see_also: ["system:tiberium", "Storage"]
when_omitted:
  kind: value
  value: "no"
---

With `SiloDamage=yes`, the building shows how full it is. It runs its [`SpecialAnim`](/keys/specialanim/) animation as a fill indicator and holds it on a frame chosen by how much Tiberium the building itself stores, as a share of its [`Storage`](/keys/storage/):

| Stored share of `Storage` | Indicator |
| --- | --- |
| Less than 1/8 | Not shown |
| 1/8 to less than 3/8 | Frame 1 |
| 3/8 to less than 5/8 | Frame 2 |
| 5/8 or more | Frame 3 |

A building with no `Storage` never shows the indicator.

Frames count from the animation's [`Start`](/keys/start/) frame, which is frame 0 and is never shown. The indicator holds the frame for its fill level and does not play through its frames on its own.

The indicator always starts in its healthy form. [A storage structure](/keys/specialanim/#a-storage-structure) covers how it uses the special slots.

:::danger[Name a SpecialAnim for every SiloDamage=yes building]
The game crashes when the building's stored share first reaches 1/8 if its `SpecialAnim=` is missing or names an animation that no `[Animations]` entry registers. Setting only [`SpecialAnimDamaged=`](/keys/specialanimdamaged/) does not prevent the crash.
:::
