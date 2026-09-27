---
key: MaxDC
summary: The frames between one particle's damage applications.
see_also: ["Damage", "Warhead", "FinalDamageState", "MaxEC"]
when_omitted:
  kind: value
  value: "0"
---

A `Gas` or `Fire` particle applies its [`Damage`](/keys/damage/#scope-particletype) through its [`Warhead`](/keys/warhead/#scope-particletype) once every `MaxDC` frames, starting `MaxDC` frames after it is created. `MaxDC=1` applies damage every frame, and `60` once every four seconds at 15 frames a second. The [`BehavesLike` behavior table](/keys/behaveslike/#scope-particletype) lists which objects each of the two damages.

No other behavior uses the interval. `WeakGas` particles never apply damage. `Web` particles apply their warhead every frame, whatever this value is. `Smoke`, `Spark` and `Railgun` particles do no damage.

:::caution[Set MaxDC on a damaging particle]
With `MaxDC=0`, the particle's first countdown wraps to 65,535 frames, longer than any particle lives. A type with `Damage` and a `Warhead` but no interval therefore never harms anything.
:::
