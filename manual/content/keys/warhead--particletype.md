---
key: Warhead
scope: particletype
label: Particle warhead
see_also: ["Damage", "MaxDC", "FinalDamageState", "BehavesLike"]
when_omitted:
  kind: value
  value: none
---

`Warhead` names the warhead a particle applies to the objects in its cell. Only `Gas`, `Fire` and `Web` [behaviors](/keys/behaveslike/#scope-particletype) use it. `WeakGas`, `Smoke`, `Spark` and `Railgun` particles deal no damage, so the setting does nothing for them.

A `Gas` particle hits every object in its cell once every [`MaxDC`](/keys/maxdc/) frames, applying its [`Damage`](/keys/damage/#scope-particletype) through this warhead. The warhead's armor multipliers and its [`Spread`](/keys/spread/#scope-warheadtype) decide how much each object takes.

A `Fire` particle does the same while its animation state is at or below [`FinalDamageState`](/keys/finaldamagestate/). It never hits the object that fired it.

A `Gas` or `Fire` particle deals no damage when it has no warhead or when `Damage=0`.

A `Web` particle hits every object in its cell every frame with zero damage. It ignores `Damage`, so only the warhead's own effects apply. A `Web` particle with no warhead affects nothing.

`Warhead=none` and `Warhead=<none>` both clear the setting. A name that matches no warhead creates a new warhead of that name, so a misspelled name produces a warhead with no section of its own and every setting at its default.
