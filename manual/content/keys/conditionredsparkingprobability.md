---
key: ConditionRedSparkingProbability
summary: Chance each frame that a critically damaged object starts throwing sparks.
see_also: [ConditionYellowSparkingProbability, ConditionRed, DamageParticleSystems]
when_omitted:
  kind: value
  value: ".02"
---

While an object's strength is below [`ConditionRed`](/keys/conditionred/), this is the chance each frame that it starts throwing damage sparks. The value is a fraction: `0` never starts sparks, and `1` or more starts them on practically every frame the chance is drawn. Between `ConditionRed` and [`ConditionYellow`](/keys/conditionyellow/), [`ConditionYellowSparkingProbability`](/keys/conditionyellowsparkingprobability/) applies instead.

An object carries at most one spark system at a time, and no chance is drawn while one is running. The value therefore sets how soon a new spark system follows the last one, not how many sparks show at once.

Sparks can start only when **all of** these hold:

- the type's [`DamageParticleSystems`](/keys/damageparticlesystems/) names at least one ParticleSystemType with [`BehavesLike=Spark`](/keys/behaveslike/#scope-particlesystemtype);
- the object is less than 10 leptons below ground level;
- the object is a vehicle, an aircraft or a structure, or infantry whose type sets [`Cyborg=yes`](/keys/cyborg/).

The spark system is one of those `Spark` entries, picked at random, placed at the type's [`DamageSmokeOffset`](/keys/damagesmokeoffset/) from the object's center.
