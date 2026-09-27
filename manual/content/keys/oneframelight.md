---
key: OneFrameLight
summary: Whether a system's light is redrawn every frame at a brightness that follows how full of particles it is.
see_also: [LightSize, ParticleCap, BehavesLike]
when_omitted:
  kind: value
  value: "no"
---

With `OneFrameLight=yes`, a system of any [behavior](/keys/behaveslike/#scope-particlesystemtype) draws a glow on every frame it holds at least one particle, at every detail setting. The system also needs a positive [`LightSize`](/keys/lightsize/).

The glow's strength is `LightSize` scaled by how full the system is: the number of particles it holds divided by [`ParticleCap`](/keys/particlecap/). The scale never falls below four tenths and never rises above the whole. The light therefore brightens as the system fills, dims as it empties, and goes out when the last particle expires.

```ini title="rules.ini"
[MyWeldingSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Spark
HoldsWhat=MyWeldingSpark ; a ParticleType registered in [Particles]
ParticleCap=25
SparkSpawnFrames=20
LightSize=25
OneFrameLight=true
```

With `OneFrameLight=no`, only a `Spark` system lights anything: it throws one short glow if its first frame throws a burst, as [`LightSize`](/keys/lightsize/) describes. Setting the flag replaces that glow, so a spark system has one light or the other, never both. For a smoke plume or a gas cloud, the flag is the only way to cast a light.

A `Spark` system's glow flickers while the system is still throwing bursts. On about three frames in five, the glow steps a little larger or smaller, between about three fifths and all of its full size. After the last burst it keeps its last size. A system of any other behavior draws a steady glow at about four fifths of its full size, which changes only with the particle count.
