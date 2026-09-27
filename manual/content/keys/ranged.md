---
key: Ranged
summary: Gives the projectile a fuel supply, detonating it once it has flown the firing weapon's projectile range.
see_also: [ProjectileRange, Range, Arm]
when_omitted:
  kind: value
  value: "no"
---

The projectile carries a flight allowance and detonates wherever it is when the allowance runs out. Each game frame, the distance it moved is taken off the allowance. Homing and ballistic projectiles spend it the same way.

The allowance is the firing weapon's [`ProjectileRange`](/keys/projectilerange/), not its [`Range`](/keys/range/). `Range` is how far away the weapon may fire from, and `ProjectileRange` is how far the shot may then travel. A weapon that does not set `ProjectileRange` gives its projectile about 390 cells, so a `Ranged=yes` projectile needs `ProjectileRange` on its weapon to run out in practice.

A bomblet released by a [`Splits=yes`](/keys/splits/) projectile takes its allowance from its [`AirburstWeapon`](/keys/airburstweapon/)'s `Range` instead.

```ini title="rules.ini"
[MYROCKET] ; a BulletType, registered by a weapon naming it as its Projectile
Image=MISSILE
ROT=5
Ranged=yes

[MyRocketLauncher] ; a WeaponType, registered by an object naming it as its Primary
Projectile=MYROCKET
Range=7
ProjectileRange=9 ; the rocket may fly 9 cells, 2 more than the firing range
```
