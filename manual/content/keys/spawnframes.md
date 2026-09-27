---
key: SpawnFrames
summary: The starting interval, in game frames, between a smoke or fire system's particle spawns.
see_also: [BehavesLike, Slowdown, SpawnCutoff, SpawnTranslucencyCutoff, NaturalParticleSystem]
when_omitted:
  kind: value
  value: "1"
---

A `Smoke` or `Fire` system emits a particle on each game frame whose number is a multiple of this interval. `10` emits on every tenth frame. At the default [game speed](/keys/gamespeed/), that is twice a second in a multiplayer game and three times a second in a campaign mission or skirmish. Only the `Smoke` and `Fire` [behaviors](/keys/behaveslike/#scope-particlesystemtype) read it.

```ini title="rules.ini"
[MySmokeSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Smoke
HoldsWhat=MySmokePuff ; a ParticleType registered in [Particles]
SpawnFrames=10
Slowdown=.0025
SpawnCutoff=15.0
```

A smoke system starts its working interval at this figure and lengthens it by [`Slowdown`](/keys/slowdown/) every frame, so this figure sets only the plume's opening rate. Two settings are compared with the working interval, not with this figure. [`SpawnCutoff`](/keys/spawncutoff/) ends the plume once the interval passes it, and [`SpawnTranslucencyCutoff`](/keys/spawntranslucencycutoff/) makes new particles more translucent once the interval passes it.

New smoke particles also rise more slowly as the working interval grows. A new particle starts `0.35` leptons a frame slower for each frame by which the working interval exceeds this figure, and no new particle starts slower than `2` leptons a frame. A plume set to `10` and ended at `15` starts its last particles up to `1.75` slower than its first, less if that floor applies.

A fire system keeps its interval at this figure, and `Slowdown` does not apply. While its firer has a target and is still turning toward it, the system also emits on every third frame, so the stream thickens as the firer comes around.

When a blow takes a structure from half strength or above to below half, the working interval of its [`NaturalParticleSystem`](/keys/naturalparticlesystem/) is multiplied by `1.5`. A smoke plume then thins at once and moves closer to its `SpawnCutoff`, which it may pass straight away.

:::danger[Keep SpawnFrames above zero]
A `Smoke` or `Fire` type with `SpawnFrames=0` crashes the game with a division by zero on the first frame a system of that type runs.
:::
