---
key: SpiralDeltaPerCoord
summary: How far a railgun trace's corkscrew turns per lepton of beam length, in radians.
see_also: [BehavesLike, SpiralRadius, ParticlesPerCoord, PositionPerturbationCoefficient]
when_omitted:
  kind: value
  value: ".025"
---

Each particle's angle around the beam is its distance from the muzzle multiplied by this value, so the corkscrew winds at the same rate on a short shot and a long one. Distance is in leptons, 256 to a cell, and the angle is in radians: `.025` turns a little more than once per cell, and `.035` about one and a half times. A negative value winds the coil the other way. Only the `Railgun` [behavior](/keys/behaveslike/#scope-particlesystemtype) reads it.

```ini title="rules.ini"
[MyRailgunSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Railgun
HoldsWhat=MyRailgunPart ; a ParticleType registered in [Particles]
SpiralDeltaPerCoord=.035
SpiralRadius=6
ParticlesPerCoord=.1 ; about 18 particles to each turn of the coil
```

A tighter wind spreads the same particles over more turns. Each turn gets about 6.28 times [`ParticlesPerCoord`](/keys/particlespercoord/) divided by this value, which gives the 18 in the example above. Raise `ParticlesPerCoord` along with this value to keep that count up; once a turn has only a handful of particles, they no longer outline a coil.

At zero the particles do not circle the beam. They form a straight line beside it, [`SpiralRadius`](/keys/spiralradius/) away.
