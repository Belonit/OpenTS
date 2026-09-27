---
key: SpawnRadius
summary: How far a smoke system scatters its new particles from its own position, in leptons.
see_also: [BehavesLike, SpawnFrames, NaturalParticleLocation, DamageSmokeOffset]
when_omitted:
  kind: value
  value: "0"
---

A `Smoke` system places each new particle up to this many leptons from its own position along each of the two horizontal map axes. The two offsets are random and independent, so the column rises from a square patch around the system. A cell is 256 leptons across, so a radius of `10` keeps the patch under a tenth of a cell wide. Each particle also starts ten leptons above the system, and no setting changes that.

```ini title="rules.ini"
[MySmokeSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Smoke
HoldsWhat=MySmokePuff ; a ParticleType registered in [Particles]
SpawnFrames=10
SpawnRadius=10 ; particles appear within ten leptons of the plume's base
```

Only the `Smoke` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it. The radius spreads particles around the plume but does not move the plume itself. A structure's natural plume is placed by [`NaturalParticleLocation`](/keys/naturalparticlelocation/), and a damage plume by [`DamageSmokeOffset`](/keys/damagesmokeoffset/).

:::danger[Keep SpawnRadius at 0 or above]
`SpawnRadius=-1` divides by zero and crashes the game on the first frame the plume would emit a particle.
:::
