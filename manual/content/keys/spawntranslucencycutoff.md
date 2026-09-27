---
key: SpawnTranslucencyCutoff
summary: The spawn interval past which a smoke system raises its new particles' fade level by one step.
see_also: [BehavesLike, SpawnFrames, Slowdown, SpawnCutoff, Translucency]
when_omitted:
  kind: value
  value: "0.0"
---

Once a smoke system's spawn interval grows past this value, every particle it emits from then on starts with a fade level one step of 25 above the particle type's [`Translucency`](/keys/translucency/#scope-particletype). The interval starts at [`SpawnFrames`](/keys/spawnframes/) and grows by [`Slowdown`](/keys/slowdown/) every frame, so this value picks the point in the plume's life where the step begins. Only the `Smoke` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it.

Where the value sits against the other two interval settings decides which particles get the step:

- Between `SpawnFrames` and [`SpawnCutoff`](/keys/spawncutoff/): the last stretch of emission gets the step, before the plume stops emitting.
- Below `SpawnFrames`: every particle the plume emits gets the step. Omitting the key puts it here.
- At or above `SpawnCutoff`: no particle gets the step, because the system stops emitting first.

```ini title="rules.ini"
[MySmokeSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Smoke
HoldsWhat=MySmokePuff ; a ParticleType registered in [Particles]
SpawnFrames=10
Slowdown=.0025
SpawnTranslucencyCutoff=13.0 ; step begins about 1200 frames in
SpawnCutoff=15.0 ; emission stops about 2000 frames in
```

The cutoff is tested only when the system emits a particle. A [`NextParticle`](/keys/nextparticle/) successor from a split starts from its parent's fade level, step included, as [`Translucency`](/keys/translucency/#scope-particletype) describes.

What the step changes on screen depends on the particle type's `Translucency`. Only three fade levels are drawn, and only at the High detail setting; below it, no particle is faded at all. At High detail:

| Type's `Translucency` | Before the cutoff | After the cutoff |
| --- | --- | --- |
| `0` | Solid | A quarter faded |
| `25` | A quarter faded | Half faded |
| `50` | Half faded | Three quarters faded |
| `51` to `74` | Solid | Three quarters faded |
| `75` to `102` | Three quarters faded | Three quarters faded |
| `103` to `127` | Three quarters faded | Solid |
| Any other value from `1` to `49` | Solid | Solid |

A particle holds its fade level between `-128` and `127`. Adding the step to `103` or more passes `127`, so the level wraps below zero and the particle draws solid. A type value outside that range wraps first, as [`Translucency`](/keys/translucency/#scope-particletype) describes; one that wraps below zero draws solid with or without the step.
