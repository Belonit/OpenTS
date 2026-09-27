---
key: Proximity
summary: Parsed flag that the engine never uses.
no_effect: true
see_also: [Arm, ROT]
when_omitted:
  kind: value
  value: "no"
---

Every homing projectile, one with [`ROT`](/keys/rot/#scope-bullettype) above `0`, already has a proximity fuse that detonates it near the point where its target stood at launch, and `Proximity=no` does not remove it. [`Arm`](/keys/arm/) delays that fuse.
