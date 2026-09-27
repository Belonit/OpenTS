---
key: AnimPalette
summary: Draws the projectile's body with the animation palette instead of the normal one.
see_also: [Image, Voxel]
when_omitted:
  kind: value
  value: "no"
---

Only the body changes palette. The shadow under a projectile above the ground is drawn with the normal palette either way. A [`Voxel=yes`](/keys/voxel/) projectile ignores this setting, because it takes its colors from [`Color`](/keys/color/#scope-bullettype).

The setting is read from the art section named by the projectile's [`Image`](/keys/image/). Write `Image=` in the projectile's rules section even when it would name the section itself. Without it, this setting is not read, not even from an art section named after the projectile, as [where a projectile's artwork is read from](/systems/projectile-flight/#where-a-projectiles-artwork-is-read-from) explains.
