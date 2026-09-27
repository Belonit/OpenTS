---
key: Damage
scope: particletype
label: Particle damage
when_omitted:
  kind: value
  value: "0"
---

The damage a [`Gas` or `Fire`](/keys/behaveslike/#scope-particletype) particle applies, through its [`Warhead`](/keys/warhead/#scope-particletype), to objects in its cell. It is applied once every [`MaxDC`](/keys/maxdc/) frames. At `0` the particle does no damage.

A `Fire` particle never damages the object its particle system is attached to, and stops damaging once its animation state passes [`FinalDamageState`](/keys/finaldamagestate/).

A `Web` particle applies its warhead at zero damage and ignores this value. Particles of other behaviors apply no damage.
