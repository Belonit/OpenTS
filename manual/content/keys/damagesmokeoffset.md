---
key: DamageSmokeOffset
summary: Where a damaged object's spark and smoke systems are anchored, relative to the object.
see_also: [DamageParticleSystems, NaturalParticleLocation]
when_omitted:
  kind: value
  value: 0,0,0
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
DamageParticleSystems=MYSPARKSYS,MYSMOKESYS ; ParticleSystemTypes registered in [ParticleSystems]
DamageSmokeOffset=0,0,90 ; sparks and smoke start 90 leptons above the tank
```

The offset is three lepton distances, X, Y and Z, added to the object's anchor point when one of its [`DamageParticleSystems`](/keys/damageparticlesystems/) is created. X and Y are map directions, so the offset does not turn with the object's facing.

Sparks are anchored at the object's center and smoke at its position. On a vehicle, infantryman or aircraft these are the same point. On a structure the center is the middle of its footprint and the position is its reference cell, so the two anchors differ horizontally but not in height.

A smoke system then moves with a vehicle, infantryman or aircraft, so on those the offset sets where the plume sits on the object. A spark burst stays at the point where it started.

:::note[A value with fewer than three components reads as the default]
`DamageSmokeOffset=0,90` has only two of the three components an offset needs, so the key reads as its default and the debug log records the line. [INI syntax](/formats/ini-syntax/#malformed-values) has the rule.
:::
