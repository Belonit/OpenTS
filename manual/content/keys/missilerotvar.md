---
key: MissileROTVar
summary: How far a homing projectile's rate of turn swings above its nominal value.
see_also: [MissileSpeedVar, ROT]
when_omitted:
  kind: value
  value: ".25"
---

`MissileROTVar` makes homing projectiles weave. It applies to every projectile whose BulletType has a [`ROT`](/keys/rot/#scope-bullettype) above zero.

A homing projectile's turn rate swings over a 15-frame cycle. At the bottom of the cycle the projectile turns at its `ROT`, and at the top it turns at `ROT` × (1 + 2 × `MissileROTVar`). A larger value makes the weave wider. At `0` the projectile turns at its `ROT` throughout and flies without weaving.

Each projectile starts the cycle at a different point, so missiles launched together do not weave in step.

Two cases override the cycle:

- A projectile fired by a weapon whose [`Speed`](/keys/speed/#scope-weapontype) is below `40` does not turn until it has accelerated to that speed.
- A projectile within one cell of its target turns 1.5 times as fast as the cycle allows.

[Steered flight](/systems/projectile-flight/#steered-flight) explains how the turn rate steers the projectile.
