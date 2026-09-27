---
key: XVelocity
summary: One horizontal axis of the spread of speeds a spark is thrown at.
see_also: ["YVelocity", "MinZVelocity", "ZVelocityRange", "BehavesLike"]
when_omitted:
  kind: value
  value: "1"
---

```ini title="rules.ini"
[MYSPARK] ; a ParticleType registered in [Particles]
BehavesLike=Spark
MaxEC=500
XVelocity=10 ; sparks are thrown under 10 leptons a frame along this axis, either way
YVelocity=10
MinZVelocity=40
ZVelocityRange=15
```

A spark system throws each particle at a random speed along this axis, in leptons a frame. The speed is anything below this value, in either direction. A negative value gives the same spread as its positive counterpart.

This setting, [`YVelocity`](/keys/yvelocity/) and [`ZVelocityRange`](/keys/zvelocityrange/) together set how fast each spark travels and which way it starts. Larger values make the burst faster and more scattered.

The system then adds a vector to each spark's random speed and scales the sum back to that speed, so the vector changes only the spark's heading. Most systems add their [`SpawnDirection`](/keys/spawndirection/), which leaves the heading unchanged at its default of `0,0,0`. The firestorm explosions thrown by [`DefaultFirestormExplosionSystem`](/keys/defaultfirestormexplosionsystem/) add one random vector shared by the whole burst instead. `SpawnDirection` explains how far the vector turns the heading.

Only a [particle system](/systems/particle-systems/) with [`BehavesLike=Spark`](/keys/behaveslike/#scope-particlesystemtype) reads these settings. It reads them from the type its `HoldsWhat=` names, whatever that type's own [`BehavesLike`](/keys/behaveslike/#scope-particletype). A type held by any other kind of system ignores them.

:::danger[Keep XVelocity nonzero]
`XVelocity=0` divides by zero and crashes the game when a spark system holding the type throws its first burst.
:::
