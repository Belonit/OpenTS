---
key: Projectile
summary: The BulletType the weapon launches.
see_also: ["Warhead", "Speed", "ProjectileRange", "Range", "system:target-selection"]
when_omitted:
  kind: value
  value: none
---

The projectile controls how the shot travels and what it may be aimed at. The weapon controls how hard the shot hits and how often it fires. Homing, arcing, bouncing, burning fuel and whether the shot is drawn at all belong to the named BulletType. So do the [`AA`](/keys/aa/) and [`AG`](/keys/ag/) flags, which decide whether the weapon may fire at objects in the air and on the ground. Those two flags and the [`AV`](/keys/av/) flag also decide [which targets an object scanning for one considers](/systems/target-selection/#what-each-kind-of-object-considers).

```ini title="rules.ini"
[MyMissileGun] ; example WeaponType
Projectile=MyRocket ; a BulletType, registered by a weapon naming it as its Projectile
Warhead=AP         ; a WarheadType registered in [Warheads]
Damage=60
Range=8

[MyRocket] ; example BulletType
ROT=20
AA=yes
```

The projectile also decides whether the weapon's [`Speed=`](/keys/speed/#scope-weapontype) is used. When the projectile does not home (`ROT=0`), the weapon's launch speed is worked out from its [`Range=`](/keys/range/) after the rules have been read, replacing `Speed=`.

A name that matches no known projectile creates a new BulletType of that name. A misspelled name therefore gives the weapon a projectile with none of the intended settings instead of an error. `Projectile=` with nothing after the `=` counts as not set and keeps whatever an earlier rules file set.

:::danger[A weapon with no projectile crashes the game]
`Projectile=none`, or leaving the key unset, leaves the weapon with no projectile. The game then crashes the first time it reads the projectile's flags. That happens when an object checks whether it can fire at a target, measures its range to one, or lists the kinds of object it may scan for, and when a house rates its base defenses. For a structure with [`IsBaseDefense=yes`](/keys/isbasedefense/), the rating of its first-slot weapon runs as soon as the rules have been read, so the game crashes before the scenario starts. Name a projectile for every weapon an object can hold, whether or not it is meant to be fired.
:::
