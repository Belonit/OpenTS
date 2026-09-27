---
key: DamageParticleSystems
summary: The particle systems a damaged object gives off, sorted into sparks and smoke by their own behavior.
see_also: [DamageSmokeOffset, ConditionYellow, ConditionRed, ConditionYellowSparkingProbability, ConditionRedSparkingProbability, Cyborg]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
DamageParticleSystems=MYSPARKSYS,MYSMOKESYS ; ParticleSystemTypes registered in [ParticleSystems]
DamageSmokeOffset=0,0,90
```

Each entry's [`BehavesLike`](/keys/behaveslike/) decides its role. `Spark` entries supply the object's damage sparks and `Smoke` entries supply its damage smoke. An entry with any other behavior is never used.

**Sparks start by chance.** On every frame that a damaged object meets **all of** these, it rolls for sparks:

- its strength is below [`ConditionYellow`](/keys/conditionyellow/);
- it is less than ten leptons underground;
- it has no spark system running.

The chance is [`ConditionYellowSparkingProbability`](/keys/conditionyellowsparkingprobability/), or [`ConditionRedSparkingProbability`](/keys/conditionredsparkingprobability/) once the object is below [`ConditionRed`](/keys/conditionred/). On success, one `Spark` entry, chosen at random, starts at the object's center plus [`DamageSmokeOffset`](/keys/damagesmokeoffset/). The burst stays at that point and ends by itself once its [`SparkSpawnFrames`](/keys/sparkspawnframes/) have passed; repair does not cut it short.

Damage sparks share a slot with the spray of a [`UseSparkParticles=yes`](/keys/usesparkparticles/) weapon. While damage sparks are running, such a weapon cannot fire. While its spray is running, no damage sparks start.

**Smoke starts on a hit.** A damaging hit attaches one `Smoke` entry, chosen at random, when **all of** these hold:

- the object's strength is at or below `ConditionYellow` after the hit;
- the hit takes the object below half strength or below `ConditionRed`, or is the killing hit a [`Cyborg=yes`](/keys/cyborg/) soldier survives by going prone;
- it has no smoke system running;
- it is less than ten leptons underground.

The smoke is attached at the object's position plus `DamageSmokeOffset`. Healing or repair that lifts the object back above `ConditionYellow` removes it, and so does travel more than ten leptons underground.

An object runs at most one spark system and one smoke system at a time, so a longer list widens the choice, not the count.

:::caution[A cyborg's sparks depend on the last rules file]
An InfantryType gives off sparks only if it is `Cyborg=yes`; every other kind of object can spark. Every rules file the game reads, including the scenario, switches an InfantryType's sparks off unless that file contains the type's section and the type is `Cyborg=yes`. A `Cyborg=yes` type therefore sparks only when the last rules file read for the scenario also contains its section.
:::
