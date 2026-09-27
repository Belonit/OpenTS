---
key: SpiralRadius
summary: The radius of the corkscrew a railgun trace winds around its beam, in leptons.
see_also: [BehavesLike, SpiralDeltaPerCoord, ParticlesPerCoord, PositionPerturbationCoefficient]
when_omitted:
  kind: value
  value: "25.0"
---

Each particle of the trace is placed this far from its point on the beam, at the angle [`SpiralDeltaPerCoord`](/keys/spiraldeltapercoord/) gives it. The value is in leptons, 256 to a cell, so the stock traces' radii of `6` and `15` keep the coil well inside a cell's width. Only the `Railgun` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it.

The radius is only where the particles start. Each `Railgun` particle then travels away from the beam at its speed, as [`MovementPerturbationCoefficient`](/keys/movementperturbationcoefficient/) describes, so the coil widens over the trace's life while that speed stays positive. The speed starts at the particle type's [`Velocity`](/keys/velocity/), `.4` and `.3` for the stock traces, plus the offset [`VelocityPerturbationCoefficient`](/keys/velocityperturbationcoefficient/) adds, and drifts a little each frame. A `Spark` particle ignores its speed and falls under gravity, and particles of other behaviors stay where they were created.

```ini title="rules.ini"
[MyRailgunSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Railgun
HoldsWhat=MyRailgunPart ; a ParticleType registered in [Particles]
SpiralRadius=15
SpiralDeltaPerCoord=.03
PositionPerturbationCoefficient=10 ; example value: scatter of up to 5 leptons, a third of the radius
```

[`PositionPerturbationCoefficient`](/keys/positionperturbationcoefficient/) then moves each particle by up to half its value along each axis, in the same leptons. The coil keeps its shape only while that scatter stays well inside this radius. Both stock traces scatter at least as far as their radius: up to `10` leptons along each axis against a radius of `6`, and up to `15` against `15`.
