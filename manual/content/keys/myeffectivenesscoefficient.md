---
key: MyEffectivenessCoefficient
summary: Weights a candidate target by how much damage this object's warhead does to that candidate's armor.
see_also: ["system:target-selection"]
when_omitted:
  kind: computed
  note: Takes the value of MyEffectivenessCoefficientDefault in [General], which is itself 0 when that key is absent too.
---

During [automatic target selection](/systems/target-selection/), the coefficient multiplies the [`Verses`](/keys/verses/) value of the warhead this object would use against a candidate, taken for the candidate's [armor class](/reference/enums/armor/). A `Verses` value of `100%` counts as `1`. A positive coefficient draws the object toward candidates it damages well, and a negative one steers it away from them.

The value comes from the type of the object doing the choosing. The candidate's setting plays no part.

```ini title="rules.ini"
[MYTANK] ; example UnitType
MyEffectivenessCoefficient=2
```

:::caution[A zero does not survive a later rules layer]
A stored `0` counts as unset. Each later rules layer that contains the type's section, such as the expansion rules or the map, reads the key again. If that copy of the section omits the key, the `0` is replaced by [`MyEffectivenessCoefficientDefault`](/keys/myeffectivenesscoefficientdefault/). To keep `0` on one type, write `MyEffectivenessCoefficient=0` in every layer that contains its section, or set the `[General]` default to `0` as well.
:::
