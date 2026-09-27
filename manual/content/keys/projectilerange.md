---
key: ProjectileRange
summary: How far a fueled projectile may fly before it detonates wherever it happens to be, in cells.
see_also: ["Ranged", "Projectile", "Range"]
when_omitted:
  kind: value
  value: "390.625"
---

Only a projectile with [`Ranged=yes`](/keys/ranged/) uses this value. The shot starts with this much fuel and spends the distance it covers on each move. When the fuel runs out, the shot detonates where it is, which stops a missile from chasing an evading target across the map. Other projectiles ignore the value.

The value comes from the weapon that fires the shot, so two weapons that share a projectile can give its shots different amounts of fuel.

```ini title="rules.ini"
[MyMissile] ; example WeaponType
Range=12
ProjectileRange=14 ; the missile can fly two cells farther than Range
Projectile=MyRocket ; a BulletType, registered by a weapon naming it as its Projectile

[MyRocket] ; example BulletType
Ranged=yes
ROT=20
```

The value is in cells, and a fraction is accepted. With the key unset, a fueled projectile can fly about 390 cells before its fuel runs out.

`-1` counts as not set, so it keeps whatever an earlier rules file set.

Some shots take their fuel from another setting:

- A bomblet thrown by an [`AirburstWeapon=`](/keys/airburstweapon/) uses that weapon's [`Range=`](/keys/range/).
- The trigger actions that launch a cluster missile and a chemical missile use the `ProjectileRange` of the weapons named `MultiLauncher` and `ChemLauncher`.
