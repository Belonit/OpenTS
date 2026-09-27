---
key: Rotates
summary: Draws the projectile from a set of 32 facing frames instead of always from the same one.
see_also: [Image, AnimLow, AnimHigh, Voxel]
when_omitted:
  kind: value
  value: "no"
---

The projectile is drawn from one of 32 facing frames, picked from its current heading. Without the setting, every projectile of the type is drawn from the first frame of its artwork whichever way it points.

A flight animation takes precedence. While [`AnimLow`](/keys/animlow/) or [`AnimHigh`](/keys/animhigh/) is other than `0`, the animation frame is drawn and the heading is ignored, so the two cannot be combined. A [`Voxel=yes`](/keys/voxel/) projectile is turned in three dimensions and ignores both this setting and the flight animation.

The key belongs in the art section that the projectile's [`Image`](/keys/image/) names, and it is read only when the projectile's rules section sets `Image=`. [Where a projectile's artwork is read from](/systems/projectile-flight/#where-a-projectiles-artwork-is-read-from) explains what happens without it.
