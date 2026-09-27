---
key: ROT
scope: bullettype
label: Projectile rate of turn
when_omitted:
  kind: value
  value: "0"
---

Any figure above `0` makes the projectile a homing one. A homing projectile steers toward its target and over terrain in the way. A projectile at `0` follows the path it was launched on until it hits something. [Steered flight](/systems/projectile-flight/#steered-flight) describes the homing flight model.

The figure is how far the projectile may turn in one game frame, in 256ths of a full turn. The turn is not constant: [`MissileROTVar`](/keys/missilerotvar/) swings it above the written figure so that missiles weave, and a projectile within a cell of its target turns half again as fast. A newly fired projectile turns only slightly until it has accelerated to its speed. [Steered flight](/systems/projectile-flight/#steered-flight) describes this launch phase and the fast shots that skip it.

Homing also changes the launch:

- The shot leaves in the direction the firer faces, such as its turret's facing, instead of being aimed at the target.
- The projectile accelerates to the weapon's [`Speed`](/keys/speed/#scope-weapontype) as written. A weapon whose projectile has `ROT=0` has that speed replaced by one worked out from its [`Range`](/keys/range/).

Aircraft treat two figures specially:

- At `ROT=0`, the shot leaves level along the aircraft's heading at the aircraft's current speed.
- At `ROT=1`, the aircraft aims the shot straight at its target and launches it at the speed of the aircraft's primary weapon.

An aircraft makes strafing runs only when the projectile of its first weapon has a `ROT` of `1` or less.
