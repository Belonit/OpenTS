---
key: HoldsWhat
summary: The ParticleType every particle a system creates is made from.
see_also: [BehavesLike, NextParticle, Particle]
when_omitted:
  kind: value
  value: ""
  note: The empty name is registered as a ParticleType of its own, so the system holds a blank particle with every built-in value. A later file that contains the section without this key puts that blank particle back.
---

Every particle a system emits by its [behavior](/keys/behaveslike/#scope-particlesystemtype) is of this type. So is the single particle a system receives from a warhead's blast, an exploding barrel, a web, or a levitating vehicle's gas puff. A veinhole monster's gas release is the exception: it always adds a `GasCloudM1` particle to the scenario's shared gas cloud. A particle's [`NextParticle`](/keys/nextparticle/) decides what it turns into when it expires, so a gas cloud or a smoke column can end up holding types this key never names.

```ini title="rules.ini"
[MySparkSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Spark
HoldsWhat=MySpark ; a ParticleType registered in [Particles]
ParticleCap=12
SparkSpawnFrames=1
SpawnSparkPercentage=1
```

A name that no particle declares is registered as a new, blank particle type. A misspelled name therefore gives a system whose particles have no artwork, no damage and a life of one frame.

:::caution[A gas system named by a warhead does not use this key]
An ordinary blast from a warhead whose [`Particle`](/keys/particle/) names a system with [`BehavesLike=Gas`](/keys/behaveslike/#scope-particlesystemtype) releases its particle into the scenario's shared gas cloud. That particle comes from the shared cloud's `HoldsWhat`, so this key on the named system has no effect on that path.
:::

:::danger[`HoldsWhat=<none>` crashes a spark or railgun system]
`<none>` is the one value that names no particle. A `Spark` system with it crashes the game the first time it throws a burst. A `Railgun` system with it crashes the first time it lays a trace of at least one particle. Every other behavior, and every blast that asks a system for one particle, creates nothing instead. Name a particle, or leave the key out.
:::
