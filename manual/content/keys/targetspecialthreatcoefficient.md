---
key: TargetSpecialThreatCoefficient
summary: Weights a candidate target by the SpecialThreatValue of that candidate's type.
see_also: ["system:target-selection"]
when_omitted:
  kind: computed
  note: Takes the value of TargetSpecialThreatCoefficientDefault in [General], which is itself 0 when that key is absent too.
---

The coefficient multiplies the candidate type's [`SpecialThreatValue`](/keys/specialthreatvalue/), a value that exists only to be weighted here. The coefficient comes from the type of the object doing the choosing. Set it positive on types that should hunt whatever a mod marks with a high `SpecialThreatValue`, and negative on types that should avoid it.

```ini title="rules.ini"
[MYHUNTER] ; example UnitType
TargetSpecialThreatCoefficient=1

[MYPRIZE] ; example UnitType worth hunting
SpecialThreatValue=50
```

With these values, `MYHUNTER` adds `50` to the threat score of every `MYPRIZE` it considers.

:::caution[An explicit `0` does not last]
A `0` written on a type is replaced by [`TargetSpecialThreatCoefficientDefault`](/keys/targetspecialthreatcoefficientdefault/) at the next rules layer, such as a map, whose copy of the type's section omits this key. To keep a type at zero while that default is not zero, write `0` in every layer that contains the section.
:::
