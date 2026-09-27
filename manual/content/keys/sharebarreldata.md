---
key: ShareBarrelData
summary: Borrows the voxel model of another object type's barrel instead of loading one of the animation's own.
see_also: ["ShareSource", "ShareBodyData", "ShareTurretData", "VoxelIndex"]
when_omitted:
  kind: value
  value: "no"
---

`ShareBarrelData=yes` makes the animation draw the barrel model of the object type named by [`ShareSource`](/keys/sharesource/), the separate gun model. The animation then loads no `.VXL` file for itself.

A vehicle has a barrel model only when it has a turret. Borrowing from a type without one leaves the piece invisible.

An animation borrows only one part. The engine checks the three sharing flags in the order body, turret, barrel and uses the first one set. This flag takes effect only when neither [`ShareBodyData`](/keys/sharebodydata/) nor [`ShareTurretData`](/keys/shareturretdata/) is set.

:::danger[Repeat the flag wherever the section is declared]
A later rules or map file that declares this section without the flag makes the animation free the borrowed model and load a `.VXL` file for itself. The lending type is then drawn from freed memory, and the game frees the same memory twice when the next mission loads or the game exits. [`ShareSource`](/keys/sharesource/) describes this and the other ways a borrowed model is lost.
:::
