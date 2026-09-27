---
key: Slowdown
summary: How much a smoke system's spawn interval lengthens every frame.
see_also: [BehavesLike, SpawnFrames, SpawnCutoff, SpawnTranslucencyCutoff, WindEffect]
when_omitted:
  kind: value
  value: "0.0"
---

A `Smoke` system adds this amount to its spawn interval on every frame it runs, whether or not it emits a particle on that frame. The spawn interval is the number of frames between new particles, and it starts at [`SpawnFrames`](/keys/spawnframes/). A positive value therefore makes the plume pour fastest when it appears and thin steadily from there. Only the `Smoke` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it.

```ini title="rules.ini"
[MySmokeSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Smoke
HoldsWhat=MySmokePuff ; a ParticleType registered in [Particles]
SpawnFrames=10
Slowdown=.0025
SpawnTranslucencyCutoff=13.0
SpawnCutoff=15.0
```

Together with [`SpawnCutoff`](/keys/spawncutoff/), this amount sets how long the plume emits, because the plume stops once its interval passes the cutoff. The system above grows from `10` to `15` at `.0025` a frame. That takes 2000 frames. At the default [game speed](/keys/gamespeed/), that is 100 seconds in a multiplayer game and about 67 seconds in a campaign mission or skirmish. After 1200 of those frames it passes [`SpawnTranslucencyCutoff`](/keys/spawntranslucencycutoff/), and its new particles are more translucent from then on.

At zero the interval stays at `SpawnFrames`. With a `SpawnCutoff` at or above that, the plume emits until another route [ends it](/systems/particle-systems/#ending-a-system).

:::danger[Keep Slowdown at zero or above]
A negative value shrinks the interval. Once the interval falls between `-1` and `1`, the next frame's emission test divides by zero and the game crashes. Every negative value closer to zero than `-2` reaches that range. A plume escapes only if it ends first, such as one whose `SpawnCutoff` is below `SpawnFrames` plus this value, which ends on its first frame.
:::
