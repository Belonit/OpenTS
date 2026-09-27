---
key: SpawnSparkPercentage
summary: The chance that a spark system throws a burst on any one frame.
see_also: [BehavesLike, SparkSpawnFrames, ParticleCap]
when_omitted:
  kind: value
  value: "0.0"
---

A `Spark` system rolls against this chance on each frame it has [`SparkSpawnFrames`](/keys/sparkspawnframes/) left, and throws a burst when the roll succeeds. `.4` throws on about two frames in five, which makes the shower stutter, and `1` or above throws on every frame. The last of the `SparkSpawnFrames` always throws a burst, whatever the roll. [`ParticleCap`](/keys/particlecap/) sets the size of each burst. Only the `Spark` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it.

The value is a fraction, not a percentage: `40` throws on every frame. Write `.4`, or `40%`, since [a percent sign divides the number by 100](/formats/ini-syntax/#malformed-values).

```ini title="rules.ini"
[MySparkSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Spark
HoldsWhat=MySpark ; a ParticleType registered in [Particles]
ParticleCap=12
SparkSpawnFrames=20
SpawnSparkPercentage=.4 ; roughly two frames in five throw
```
