---
key: VoxelIndex
summary: Which section of the voxel model a voxel animation is drawn from.
see_also: ["ShareSource", "ShareBodyData", "Translucent"]
when_omitted:
  kind: value
  value: "0"
---

A voxel model holds one or more sections, and a voxel animation draws one of them together with its shadow. `VoxelIndex` picks the section by position, counting from 0. With a model borrowed through [`ShareSource`](/keys/sharesource/), the index counts that model's sections, so several animations can each draw a different section of one vehicle's model as separate pieces of wreckage.

:::caution[Lighting always follows the first section]
The piece is shaded with a lighting table built for the first section's normals. A section that uses a different normal set from the first section is shaded incorrectly.
:::

:::danger[Keep the index within the model's sections]
The engine does not check the index. An index past the last section, or a negative one, makes the piece read its data from memory outside the model. The piece is then drawn from unrelated data, or the game crashes.
:::
