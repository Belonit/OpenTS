---
key: ShareBodyData
summary: Borrows the voxel model of another object type's body instead of loading one of the animation's own.
see_also: ["ShareSource", "ShareTurretData", "ShareBarrelData", "VoxelIndex"]
when_omitted:
  kind: value
  value: "no"
---

`ShareBodyData=yes` makes the animation draw the body model of the object type named by [`ShareSource`](/keys/sharesource/), the model that type's objects are drawn with. The animation then loads no `.VXL` file for itself.

An animation borrows only one part. The engine checks the three sharing flags in the order body, turret, barrel and uses the first one set. This flag therefore wins over [`ShareTurretData`](/keys/shareturretdata/) and [`ShareBarrelData`](/keys/sharebarreldata/).

:::danger[Repeat the flag wherever the section is declared]
A later rules or map file that declares this section without the flag makes the animation free the borrowed model and load a `.VXL` file for itself. The lending type is then drawn from freed memory, and the game frees the same memory twice when the next mission loads or the game exits. [`ShareSource`](/keys/sharesource/) describes this and the other ways a borrowed model is lost.
:::
