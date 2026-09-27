---
key: UseFireParticles
summary: Attacks with a stream of fire particles instead of the projectile's damage.
see_also: ["AttachedParticleSystem", "UseSparkParticles", "ROF"]
when_omitted:
  kind: value
  value: "no"
---

Whatever damage the weapon deals comes from the particle system named in [`AttachedParticleSystem=`](/keys/attachedparticlesystem/). The system is spawned at the muzzle and aimed at the target as the shot leaves. The projectile is still created and still flies, but it carries no damage, so [`Damage=`](/keys/damage/#scope-weapontype) is never delivered.

```ini title="rules.ini"
[MyFlamer] ; example WeaponType
UseFireParticles=yes
AttachedParticleSystem=FireStreamSys ; a ParticleSystemType registered in [ParticleSystems]
ROF=30
```

A vehicle or infantry with a destination refuses to fire the weapon, even before it starts moving.

While the stream is alive, neither of the object's weapons can fire, as [Firing geometry](/systems/firing-geometry/#effects-that-hold-the-weapon-shut) describes. The next shot waits for the stream to end and for [`ROF`](/keys/rof/#scope-weapontype) to pass. The weapon's `ROF` is used as written, without the house multiplier, burst gaps or random extra frames. A structure that had more than one round of ammunition when it fired waits a single frame instead, so only the stream's lifetime paces it.

The stream ends early when the firer is given a destination, or a new target outside its first weapon's range. The particles already thrown finish their flight. The weapon can fire again once the delay set at the shot has passed. Clearing the target does not end the stream.

:::danger[Name a particle system for every fire weapon]
If [`AttachedParticleSystem=`](/keys/attachedparticlesystem/) is missing or names no registered particle system, the game crashes the first time the weapon fires.
:::
