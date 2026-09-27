---
key: Dropping
summary: Meant to make a bomb that falls from a height, but the projectile detonates as soon as it is fired.
see_also: [ROT, Arm]
when_omitted:
  kind: value
  value: "no"
---

A `Dropping=yes` projectile detonates on its first flight step, about one frame's travel from the barrel. Nothing delays the blast: neither [`Arm`](/keys/arm/) nor the distance to the target has any effect.

Two launch details still differ from an ordinary shot:

- The projectile leaves in the direction the firer faces, as a homing projectile does, instead of being aimed at the target. That is the turret's facing on a firer with a turret and the heading of an aircraft. A structure with no turret, or with a voxel turret, still aims the shot at its target.
- The firing sound plays from the firer's center instead of from the barrel.

No stock projectile sets `Dropping=yes`. To drop bombs from an aircraft, give its weapon an ordinary projectile with no [`ROT`](/keys/rot/#scope-bullettype). An aircraft launches such a projectile level along its heading at its flying speed, and gravity then pulls it down. The Orca Bomber's bombs work this way.
