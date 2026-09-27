---
key: MovementPerturbationCoefficient
summary: How far each railgun particle's course is deflected from the spiral it was laid on.
see_also: [BehavesLike, VelocityPerturbationCoefficient, PositionPerturbationCoefficient, SpiralRadius]
when_omitted:
  kind: value
  value: "0.0"
---

Randomly bends the course of each particle a `Railgun` [system](/keys/behaveslike/#scope-particlesystemtype) lays. Every other behavior ignores it. At `0`, each particle travels straight outward from the beam, along the line that placed it on the spiral.

The course starts as a direction of length one. Each of its three axes is shifted by a random amount between minus half and plus half this value, and the result is scaled back to length one. `.3` therefore shifts each axis by up to `.15` of the course's length. The deflection shows only on `Railgun` and `Spark` particles, the ones that move in a railgun system, as [The turn](/systems/particle-systems/#the-turn) explains.

```ini title="rules.ini"
[MyRailgunSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Railgun
HoldsWhat=MyRailgunPart ; a ParticleType registered in [Particles]
MovementPerturbationCoefficient=.3
VelocityPerturbationCoefficient=.6
```

:::caution[This value also caps how slow particles start]
Each particle is laid at its type's velocity plus a random offset. [`VelocityPerturbationCoefficient`](/keys/velocityperturbationcoefficient/) caps how far above that velocity the offset may go, and this value caps how far below. A larger deflection therefore also lets the trace's particles start slower. With this value at `0`, no particle starts below its type's velocity.
:::
