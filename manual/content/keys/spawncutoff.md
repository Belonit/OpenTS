---
key: SpawnCutoff
summary: The spawn interval a smoke system stops emitting at.
see_also: [BehavesLike, SpawnFrames, Slowdown, SpawnTranslucencyCutoff, Lifetime]
when_omitted:
  kind: value
  value: "0.0"
---

A `Smoke` system stops emitting once its spawn interval passes this figure. The interval starts at [`SpawnFrames`](/keys/spawnframes/), grows by [`Slowdown`](/keys/slowdown/) every frame, and is compared with this figure at the end of each frame. Puffs the system already made still turn into any successor particles their type names, and the system is removed when the last particle has expired. Only the `Smoke` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it.

A figure below `SpawnFrames` is passed on the system's first frame, so the plume emits at most one particle and stops. A type that sets neither `SpawnFrames` nor this key behaves that way.

For a plume that runs, set this figure above `SpawnFrames` and give `Slowdown` a positive value. With `Slowdown` at zero the interval never grows, and the plume emits until something else ends it.

```ini title="rules.ini"
[MySmokeSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Smoke
HoldsWhat=MySmokePuff ; a ParticleType registered in [Particles]
SpawnFrames=10
Slowdown=.0025
SpawnCutoff=15.0 ; reached after 2000 frames
```

Passing this figure is the only way a smoke system ends by itself. The other routes, such as a positive [`Lifetime`](/keys/lifetime/), are listed under [Ending a system](/systems/particle-systems/#ending-a-system).
