---
key: DefaultDebrisSmokeSystem
summary: Parsed particle system name that the engine never uses.
no_effect: true
see_also: ["DefaultFirestormExplosionSystem", "DamageParticleSystems", "AttachedParticleSystem"]
when_omitted:
  kind: value
  value: none
---

To give off particle systems, name them on the type that produces them: an object's [`DamageParticleSystems`](/keys/damageparticlesystems/), a weapon's [`AttachedParticleSystem`](/keys/attachedparticlesystem/), or a warhead's [`Particle`](/keys/particle/). None of these falls back to a `Default…System` key.

The rules hold ten `Default…System` keys, and nine of them have no effect: this one, [`DefaultFireStreamSystem`](/keys/defaultfirestreamsystem/), [`DefaultLargeGreySmokeSystem`](/keys/defaultlargegreysmokesystem/), [`DefaultLargeRedSmokeSystem`](/keys/defaultlargeredsmokesystem/), [`DefaultRepairParticleSystem`](/keys/defaultrepairparticlesystem/), [`DefaultSmallGreySmokeSystem`](/keys/defaultsmallgreysmokesystem/), [`DefaultSmallRedSmokeSystem`](/keys/defaultsmallredsmokesystem/), [`DefaultSparkSystem`](/keys/defaultsparksystem/) and [`DefaultTestParticleSystem`](/keys/defaulttestparticlesystem/). Only [`DefaultFirestormExplosionSystem`](/keys/defaultfirestormexplosionsystem/) is used, and only when the firestorm warhead destroys a vehicle or aircraft.
