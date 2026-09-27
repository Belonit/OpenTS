---
key: ShareTurretData
summary: Borrows the voxel model of another object type's turret instead of loading one of the animation's own.
see_also: ["ShareSource", "ShareBodyData", "ShareBarrelData", "VoxelIndex"]
when_omitted:
  kind: value
  value: "no"
---

`ShareTurretData=yes` makes the animation draw the turret model of the object type named by [`ShareSource`](/keys/sharesource/). The animation then loads no `.VXL` file for itself.

A turret model is a separate file from the body. A vehicle has one only when it has a turret, and borrowing from a vehicle without one leaves the piece invisible. The exception is a turretless voxel vehicle whose ID is `APC`: it keeps its `<Image ID>W.VXL` model, when that file exists, in the turret part, and this flag borrows that model.

An animation borrows only one part. The engine checks the three sharing flags in the order body, turret, barrel and uses the first one set. [`ShareBodyData=yes`](/keys/sharebodydata/) therefore overrides this flag, and this flag overrides [`ShareBarrelData`](/keys/sharebarreldata/).

:::danger[Repeat the flag wherever the section is declared]
A later rules or map file that declares this section without the flag makes the animation free the borrowed model and load a `.VXL` file for itself. The lending type is then drawn from freed memory, and the game frees the same memory twice when the next mission loads or the game exits. [`ShareSource`](/keys/sharesource/) describes this and the other ways a borrowed model is lost.
:::
