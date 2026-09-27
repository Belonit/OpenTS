---
key: Shadow
summary: Parsed flag that the engine never uses.
no_effect: true
see_also: [Voxel, High]
when_omitted:
  kind: value
  value: "yes"
---

`Shadow=no` removes no shadow. Every shape-drawn projectile above the ground has a shadow drawn beneath it, and no [`Voxel=yes`](/keys/voxel/) projectile has one, whatever this flag says.
