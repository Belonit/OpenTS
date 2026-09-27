---
key: IsRailgun
summary: Fires a beam that damages objects along the line from the muzzle to the target as the weapon fires.
see_also: ["AmbientDamage", "AttachedParticleSystem", "ROF", "Warhead"]
when_omitted:
  kind: value
  value: "no"
---

`IsRailgun=yes` fires a beam from the muzzle to the target's center at the moment the weapon fires, after the projectile has been launched. The beam damages objects along its line once each, dealing the weapon's [`AmbientDamage`](/keys/ambientdamage/) through its [`Warhead=`](/keys/warhead/#scope-weapontype). The weapon's [`AttachedParticleSystem=`](/keys/attachedparticlesystem/) is drawn along the beam.

```ini title="rules.ini"
[MyRailgun] ; example WeaponType
IsRailgun=yes
Projectile=MyBolt ; a BulletType, registered by a weapon naming it as its Projectile
AmbientDamage=200 ; the beam's damage
Damage=0          ; the projectile has none
AttachedParticleSystem=LargeRailgunSys ; a ParticleSystemType registered in [ParticleSystems]
ROF=60
```

## What the beam hits

The beam damages:

- a vehicle, infantry or aircraft in a cell the beam enters after leaving the firer's cell, when its center is within [`[CombatDamage] RailgunDamageRadius`](/keys/railgundamageradius/) of the beam's line;
- a structure in such a cell, however far its center is from the line;
- the vehicle, infantry, aircraft or structure the shot was aimed at, even if the beam did not pass through its cell.

The firing object is never damaged.

## Rising ground stops the beam

If the ground rises above the beam before it reaches the target, the beam stops there and deals no `AmbientDamage` to anything, including the target and the objects it passed on the way. At that point, a destroyable cliff may collapse at the chance [`[CombatDamage] CollapseChance`](/keys/collapsechance/) sets. The particle system is drawn only as far as the stopping point.

## The projectile still deals damage

The weapon still fires its projectile, which delivers [`Damage=`](/keys/damage/#scope-weapontype) on impact like any other shot. Set `Damage=0` for a weapon that should deal its damage through the beam alone.

## Firing rate

While the particle system is still alive, neither of the object's weapons can fire. The reload delay after a railgun shot is exactly [`ROF`](/keys/rof/#scope-weapontype), with no house rate-of-fire bias, burst delay, random extra frames or veteran bonus. The next shot waits until both `ROF` has passed and the particle system has burned out. A structure with more than one round of [`Ammo`](/keys/ammo/) left waits only for the particle system. [The reload delay](/systems/firing-geometry/#the-reload-delay) gives the full rules.

:::danger[Name a particle system]
Give every railgun weapon an `AttachedParticleSystem=`. Without one, the game crashes the first time the weapon fires. [`AttachedParticleSystem`](/keys/attachedparticlesystem/) covers the names it accepts.
:::
