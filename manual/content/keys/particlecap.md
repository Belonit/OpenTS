---
key: ParticleCap
summary: The size of a spark system's burst, and the fullness a one-frame light's brightness is measured against.
see_also: [BehavesLike, SparkSpawnFrames, SpawnSparkPercentage, OneFrameLight, LightSize]
when_omitted:
  kind: value
  value: "50"
---

A `Spark` system sizes each burst from this figure. A burst holds half the figure, rounded down, plus a random amount below that half. `12` gives bursts of six to eleven particles, and so does `13`.

```ini title="rules.ini"
[MySparkSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Spark
HoldsWhat=MySpark ; a ParticleType registered in [Particles]
ParticleCap=12 ; bursts of six to eleven
SparkSpawnFrames=1
SpawnSparkPercentage=1
```

A [`OneFrameLight`](/keys/oneframelight/) system of any behavior also uses the figure for its glow. The glow is drawn at a fraction of [`LightSize`](/keys/lightsize/): the number of particles the system holds divided by this figure, kept between `0.4` and `1`. A system holding at least this many particles glows at full `LightSize`, and the glow never drops below four tenths of it.

The figure is not a limit. A system can hold any number of particles at once. For a system of any behavior other than `Spark`, the figure affects only the `OneFrameLight` glow.

:::danger[Keep a spark system's ParticleCap at 2 or above]
`1`, `0` and `-1` all halve to zero, and a `Spark` system with one of them divides by zero and crashes the game when it throws its first burst. A figure of `-2` or below throws empty bursts.
:::
