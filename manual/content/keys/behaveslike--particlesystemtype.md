---
key: BehavesLike
scope: particlesystemtype
label: Particle system behavior
see_also: [HoldsWhat, Lifetime, Particle, DamageParticleSystems, AttachedParticleSystem]
when_omitted:
  kind: value
  value: none
  note: The read's default is no behavior, not the behavior already in force, so a later file that contains the section without this key leaves the type with no behavior at all.
---

Selects what every system of this type does on its turn. The value is one of seven names, matched without regard to letter case, so `spark` and `Spark` are the same behavior. Each behavior reads a different part of the section, and settings it does not read have no effect. [What each system behavior reads](/systems/particle-systems/#what-each-system-behavior-reads) lists them setting by setting.

| Value | What a system of the type does each frame |
| --- | --- |
| `Smoke` | Emits a particle on an interval that lengthens as the plume ages, and replaces each expiring particle that has a [`NextParticle`](/keys/nextparticle/) with two of them, thrown out to either side. It follows the object it is attached to, unless that object is a structure. |
| `Fire` | Emits a particle toward a point that sways from side to side across the line of fire. While the firer has a target and its body is still turning, the stream re-aims along the body's facing. |
| `Spark` | For a fixed number of frames, throws a burst of particles on a random chance each frame, each particle flung along a randomly deflected direction. |
| `Railgun` | On its first frame, lays one corkscrew of particles along the line from the firer to the target and, with [`Laser=yes`](/keys/laser/), draws a beam along it. After that it only ages the particles it laid. |
| `Gas`, `WeakGas`, `Web` | Drifts the particles it holds and replaces each expiring one with that particle's successor, in place. It emits nothing, so every particle it holds arrived from outside, such as from a warhead's blast, or is a successor of one that did. |

```ini title="rules.ini"
[MyRailgunSys] ; a ParticleSystemType registered in [ParticleSystems]
BehavesLike=Railgun
HoldsWhat=MyRailgunPart ; a ParticleType registered in [Particles]
SpiralRadius=15
ParticlesPerCoord=.15
Laser=yes
LaserColor=25,20,255
```

`Gas`, `WeakGas` and `Web` systems treat their particles identically. They differ in one place: an ordinary blast from a warhead whose [`Particle`](/keys/particle/) names a `Gas` system releases its particle into the scenario's shared gas cloud and builds no system of its own. A `WeakGas` or `Web` system named there is built normally.

A damaged object picks its sparks from the `Spark` entries of its [`DamageParticleSystems`](/keys/damageparticlesystems/) and its smoke from the `Smoke` entries. An entry with any other behavior is never used.

The same seven names on a [ParticleType's section](/keys/behaveslike/#scope-particletype) are a separate setting, and there `Gas`, `WeakGas` and `Web` do differ.

:::caution[A system with no behavior ends only from outside]
Omitting the key or writing an unrecognized name leaves the type with no behavior. Such a system emits nothing, and a particle put into it never ages, moves or expires. It ends only through one of the outside routes in [Ending a system](/systems/particle-systems/#ending-a-system), such as a positive [`Lifetime`](/keys/lifetime/), and even then it stays on the map while it still holds a particle. A warhead's [`Particle`](/keys/particle/) that names such a type therefore leaves a frozen particle at every impact for the rest of the scenario.
:::
