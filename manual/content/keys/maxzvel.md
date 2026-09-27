---
key: MaxZVel
summary: The top of the range a voxel animation's upward launch speed is drawn from, in leptons per frame.
see_also: ["MinZVel", "MaxXYVel", "IsMeteor"]
when_omitted:
  kind: value
  value: "5"
---

The speed is in leptons per frame (256 leptons to a cell, 15 frames to the second). Ordinary debris is thrown upward at [`MinZVel`](/keys/minzvel/#scope-voxelanimtype) plus a random whole number of leptons per frame. The largest addition is the whole-number part of the gap between the two settings, so this maximum is reached only when the gap is a whole number. A minimum of `3.5` and a maximum of `5`, for example, give launch speeds of `3.5` and `4.5` only.

A meteor ignores this setting. Its vertical speed is exactly the minimum.

:::danger[A maximum just below the minimum crashes the game]
Keep this setting at or above the minimum. A maximum less than 2 leptons per frame below it makes the random pick divide by zero, and the game crashes as soon as a piece of ordinary debris of this type is created. A meteor makes no pick and is unaffected.

A maximum 2 or more below the minimum does not crash. The speeds still start at the minimum and step upward, with two fewer steps than the same gap above the minimum would give.
:::
