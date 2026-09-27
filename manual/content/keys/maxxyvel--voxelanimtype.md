---
key: MaxXYVel
scope: voxelanimtype
label: Voxel debris lateral speed
see_also: ["MinZVel", "MaxZVel", "IsMeteor"]
when_omitted:
  kind: value
  value: "15"
---

The top horizontal speed of a piece at launch, in leptons per frame (256 leptons to a cell, 15 frames to the second). Each of the two horizontal directions gets its own speed, drawn independently from minus this setting up to it. For a whole-number setting, each draw is a whole number from minus the setting to one less than the setting, so the positive extreme is never reached.

A meteor draws both speeds the same way, then may reverse them together to keep its approach down or across the screen. [`IsMeteor`](/keys/ismeteor/#scope-voxelanimtype) describes the full flight.

:::danger[Keep this setting at 0.5 or above]
Any value between `-0.5` and `0.5`, `0` included, crashes the game when a piece of the type is created.
:::
