---
key: SparkSpawnFrames
summary: How many frames a spark system goes on throwing bursts for.
see_also: [BehavesLike, ParticleCap, SpawnSparkPercentage, LightSize, Lifetime]
when_omitted:
  kind: value
  value: "0"
---

A `Spark` system can throw bursts for this many frames. The count drops by one each frame. When it reaches zero, the system stops throwing bursts and is removed once its last particle has expired. Only the `Spark` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it.

On every frame but the last, the system throws a burst only if its [`SpawnSparkPercentage`](/keys/spawnsparkpercentage/) roll succeeds. The last frame always throws one, so `1` gives exactly one burst.

```ini title="rules.ini"
[MyWeldingSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Spark
HoldsWhat=MyWeldingSpark ; a ParticleType registered in [Particles]
ParticleCap=25
SparkSpawnFrames=20
SpawnSparkPercentage=.4
LightSize=25
OneFrameLight=true
```

A longer count does not give a longer flash. The flash described under [`LightSize`](/keys/lightsize/) can appear only on the system's first frame, and only if that frame throws a burst. The [`OneFrameLight`](/keys/oneframelight/) glow that the example uses instead is drawn for as long as the system holds any particle, so it can continue after the last burst.

:::caution[Give a spark system a positive count]
At zero or below, the system throws no bursts and never ends by itself. It stays on the map until another route ends it, such as a positive [`Lifetime`](/keys/lifetime/) or the removal of the object it belongs to. [Ending a system](/systems/particle-systems/#ending-a-system) lists the routes.
:::
