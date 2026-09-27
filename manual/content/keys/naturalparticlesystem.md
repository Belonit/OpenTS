---
key: NaturalParticleSystem
summary: A particle system a structure runs continuously from the moment it appears.
see_also: [NaturalParticleLocation, DamageParticleSystems, Cloakable]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[MYSMOKESTACK] ; a BuildingType registered in [BuildingTypes]
NaturalParticleSystem=MYSTEAMSYS ; a ParticleSystemType registered in [ParticleSystems]
NaturalParticleLocation=0,-40,180
```

The structure starts this particle system the moment it is placed on the map, whatever its health. It is the counterpart to [`DamageParticleSystems`](/keys/damageparticlesystems/), which start only once the structure is damaged. Only a BuildingType uses the key; an AircraftType, InfantryType or UnitType stores it without effect.

The system starts at the structure's position plus [`NaturalParticleLocation`](/keys/naturalparticlelocation/).

A cloaked structure loses its plume when it becomes fully transparent. Whether the plume comes back depends on [`NaturalParticleLocation`](/keys/naturalparticlelocation/).
