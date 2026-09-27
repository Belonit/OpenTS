---
key: SpawnDirection
summary: The direction a spark burst is thrown in.
see_also: [BehavesLike, ParticleCap, SparkSpawnFrames, DefaultFirestormExplosionSystem]
when_omitted:
  kind: value
  value: "0,0,0"
---

A `Spark` system adds this X, Y, Z vector to each spark's randomly drawn velocity, then scales the sum back to the speed of the draw. The vector bends the shower toward its direction without changing how fast the sparks travel.

How far it bends them depends on the vector's length compared with the draws. The draws come from the held particle type's [`XVelocity`](/keys/xvelocity/), [`YVelocity`](/keys/yvelocity/), [`MinZVelocity`](/keys/minzvelocity/) and [`ZVelocityRange`](/keys/zvelocityrange/), and the three components use the same units as those settings. A vector much longer than the draws throws every spark almost exactly along it. At `0,0,0` the sparks fly as drawn.

```ini title="rules.ini"
[MyVentSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Spark
HoldsWhat=MySpark ; a ParticleType registered in [Particles]
ParticleCap=25
SparkSpawnFrames=20
SpawnDirection=0,0,60 ; sparks thrown upward
```

Only the `Spark` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it, and firestorm explosions ignore it. When the firestorm warhead destroys an aircraft, or a vehicle without [`DeathFrames`](/keys/deathframes/), the game throws seven to nine systems of the type named by [`DefaultFirestormExplosionSystem`](/keys/defaultfirestormexplosionsystem/). Each of them draws a random direction for every burst and uses it in place of this setting, so those explosions scatter differently from one another.

:::note[Write all three components]
`SpawnDirection=0` or `SpawnDirection=0,60` has fewer than three components, so the key reads as its default and the debug log records the line. [INI syntax](/formats/ini-syntax/#malformed-values) has the rule.
:::
