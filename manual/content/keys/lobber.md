---
key: Lobber
summary: Makes the weapon always throw its shot on the high arc rather than the flat one.
see_also: ["Arcing", "Projectile", "Speed"]
when_omitted:
  kind: value
  value: "no"
---

A ballistic shot can reach a point at two launch angles, a flat one and a steep one. `Lobber=yes` makes the weapon always use the steep one. Without it, the steep angle is used only when the target is higher than the firer by more than the horizontal distance between them.

```ini title="rules.ini"
[MyMortar] ; example WeaponType
Lobber=yes
Projectile=MyShell ; a BulletType, registered by a weapon naming it as its Projectile

[MyShell] ; example BulletType
Arcing=yes
ROT=0
```

The flag changes the shot's flight only when the weapon's [`Projectile=`](/keys/projectile/) has [`Arcing=yes`](/keys/arcing/). Any other projectile sets its launch pitch without the arc choice, so it flies the same with or without the flag.

The barrel follows the arc choice whatever the projectile. Barrel elevation always uses the weapon in the object's [first weapon slot](/systems/firing-geometry/#what-each-part-of-a-shot-reads):

- A `Lobber=yes` weapon in the first slot raises the barrel to the steep angle, even when its projectile flies flat.
- A `Lobber=yes` weapon in the second slot still sends an arcing projectile on the high arc, but the barrel is aimed for the first slot's weapon.

When the first-slot weapon's launch speed cannot reach the target at either angle, the barrel falls back to a fixed elevation. When the firing weapon's launch speed cannot reach it, an arcing shot is not fired at all, so it spends no ammunition and starts no reload. [`Speed=`](/keys/speed/#scope-weapontype) covers where the launch speed comes from.
