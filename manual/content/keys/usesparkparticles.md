---
key: UseSparkParticles
summary: Sprays a particle system at the target alongside the shot.
see_also: ["AttachedParticleSystem", "UseFireParticles", "ROF"]
when_omitted:
  kind: value
  value: "no"
---

Each shot spawns one system of the type named in [`AttachedParticleSystem=`](/keys/attachedparticlesystem/) at the muzzle, aimed at the target as the shot leaves. The projectile keeps its damage: [`Damage=`](/keys/damage/#scope-weapontype) is delivered on impact as usual, and the spray adds its own effect on top.

```ini title="rules.ini"
[MySparkGun] ; example WeaponType
UseSparkParticles=yes
AttachedParticleSystem=SparkSys ; a ParticleSystemType registered in [ParticleSystems]
ROF=30
```

A vehicle with a destination refuses to fire the weapon, even before it starts moving. Infantry follow only the limits that apply to every infantry weapon, so a soldier with a destination can still fire this weapon while it is standing still. This differs from a [`UseFireParticles=yes`](/keys/usefireparticles/) weapon, which infantry also cannot fire while they have a destination.

While the spray is alive, neither of the object's weapons can fire, as [Firing geometry](/systems/firing-geometry/#effects-that-hold-the-weapon-shut) describes. The next shot waits for the spray to end and for [`ROF`](/keys/rof/#scope-weapontype) to pass. The weapon's `ROF` is used as written, without the house multiplier, burst gaps or random extra frames. A structure that had more than one round of ammunition when it fired waits a single frame instead, so only the spray's lifetime paces it.

The spray shares its place on the object with the sparks a damaged object gives off from [`DamageParticleSystems`](/keys/damageparticlesystems/). While those damage sparks are running, the object cannot fire either of its weapons, as [Particle systems](/systems/particle-systems/#the-five-holds-an-object-keeps) describes.

A weapon that also sets `UseFireParticles=yes` spawns two systems of the same type, one as a fire stream and one as a spray. It cannot fire again until both have ended.

:::danger[Name a particle system for every spark weapon]
If [`AttachedParticleSystem=`](/keys/attachedparticlesystem/) is missing or names no registered particle system, the game crashes the first time the weapon fires.
:::
