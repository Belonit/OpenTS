---
key: Laser
summary: Whether a railgun system draws a beam alongside its spiral of particles.
see_also: [BehavesLike, LaserColor, IsRailgun, IsLaser, AttachedParticleSystem]
when_omitted:
  kind: value
  value: "no"
---

With `Laser=yes`, a `Railgun` [system](/keys/behaveslike/#scope-particlesystemtype) draws a straight beam along its trace, in [`LaserColor`](/keys/lasercolor/). Every other behavior ignores the flag. The beam does not depend on the particles: a trace too short to lay any particle still draws it.

```ini title="rules.ini"
[MyRailgunSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Railgun
HoldsWhat=MyRailgunPart ; a ParticleType registered in [Particles]
Laser=yes
LaserColor=25,20,255
```

The beam appears on the frame the trace is laid and runs its full length. For an [`IsRailgun=yes`](/keys/israilgun/) weapon, that is from the firer's muzzle to the center of the target, or to the first ground that rises above the line of fire if that comes sooner.

The beam is a single line with no outer glow, and it lasts ten frames. Above the lowest detail setting, it fades from half intensity to nothing over those frames. At the lowest detail setting, it does not fade.

Set `LaserColor` along with the flag. With its default `0,0,0`, the beam is invisible above the lowest detail setting. [`LaserColor`](/keys/lasercolor/) explains how the color is applied.

This is not the beam a laser weapon fires. That beam belongs to [`IsLaser=yes`](/keys/islaser/) on the WeaponType and takes its colors from the weapon.
