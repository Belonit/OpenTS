---
key: ParticlesPerCoord
summary: How many particles a railgun trace lays per lepton of beam length.
see_also: [BehavesLike, SpiralRadius, SpiralDeltaPerCoord, Laser, AttachedParticleSystem]
when_omitted:
  kind: value
  value: ".1"
---

A `Railgun` system lays this many particles for each lepton of beam length, rounded down. The beam length is the straight-line distance from the weapon's firing point to the end of the beam. A cell is 256 leptons, so `.1` lays about 26 particles per cell of beam, and a beam five cells long gets 128. Only the `Railgun` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it.

```ini title="rules.ini"
[MyRailgunSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Railgun
HoldsWhat=MyRailgunPart ; a ParticleType registered in [Particles]
ParticlesPerCoord=.15
SpiralRadius=15
SpiralDeltaPerCoord=.03
```

The whole trace is laid on the system's first frame. The particles are spaced evenly from one end of the beam to the other whatever their number, so the figure sets how dense the trace is, not how long. A low value leaves a dotted corkscrew and a high one a solid rope.

A figure too small to give one particle, including zero and any negative value, lays no trace. The system still draws the beam if it has [`Laser=yes`](/keys/laser/), and then ends.
