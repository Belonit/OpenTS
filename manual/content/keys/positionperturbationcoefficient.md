---
key: PositionPerturbationCoefficient
summary: How far each railgun particle is displaced from its place on the spiral, in leptons.
see_also: [BehavesLike, SpiralRadius, MovementPerturbationCoefficient, VelocityPerturbationCoefficient]
when_omitted:
  kind: value
  value: "0.0"
---

A `Railgun` system moves each particle of its trace off its place on the spiral by a random offset on each of the three axes. Each axis gets its own offset, anywhere from minus half to plus half of this figure, in leptons. `30` moves a particle up to fifteen leptons along each axis. Only the `Railgun` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it.

The offset is added to the spiral position that [`SpiralRadius`](/keys/spiralradius/) sets and uses the same units. A figure more than twice `SpiralRadius` can therefore scatter a particle farther from its place than the coil's radius.

```ini title="rules.ini"
[MyRailgunSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Railgun
HoldsWhat=MyRailgunPart ; a ParticleType registered in [Particles]
SpiralRadius=6
PositionPerturbationCoefficient=20 ; scatter of up to ten leptons, wider than the coil
```

The figure changes only where each particle starts. A particle then travels outward from the coil's center line at its particle type's `Velocity`. [`MovementPerturbationCoefficient`](/keys/movementperturbationcoefficient/) varies its direction at random, and [`VelocityPerturbationCoefficient`](/keys/velocityperturbationcoefficient/) varies its speed.
