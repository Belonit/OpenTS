---
key: TargetStrengthCoefficient
summary: Weights a candidate target by how much of its maximum strength it still has.
see_also: ["system:target-selection"]
when_omitted:
  kind: computed
  note: Takes the value of TargetStrengthCoefficientDefault in [General], which is itself 0 when that key is absent too.
---

When an object of this type [scores a candidate target](/systems/target-selection/#the-threat-score), it adds this coefficient multiplied by the candidate's remaining strength as a fraction of its maximum. That fraction is `1` for an undamaged candidate and falls toward `0` as the candidate is hurt. A positive value makes the object prefer healthy candidates; a negative value makes it prefer wounded ones. The coefficient comes from the type of the object doing the choosing, never from the candidate's type.

```ini title="rules.ini"
[MYTANK] ; example UnitType
TargetStrengthCoefficient=-1
```

:::caution[A type cannot keep an explicit 0]
The engine treats a stored `0` as unset. Each rules file that contains the type's section reads this key again, and a type whose value is still `0` takes [`TargetStrengthCoefficientDefault`](/keys/targetstrengthcoefficientdefault/) instead. An explicit `0` therefore lasts only until the next rules file, such as a map, that contains the type's section without this key. Use a very small value such as `0.001` to keep the weight near zero.
:::
