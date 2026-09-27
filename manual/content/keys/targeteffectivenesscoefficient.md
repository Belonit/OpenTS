---
key: TargetEffectivenessCoefficient
summary: Weights a candidate target by how much damage that candidate's warhead does to this object's armor.
see_also: ["system:target-selection"]
when_omitted:
  kind: computed
  note: Takes the value of TargetEffectivenessCoefficientDefault in [General], which is itself 0 when that key is absent too.
---

The coefficient multiplies how badly a candidate target could hurt the object that is choosing. That measure is the [`Verses`](/keys/verses/) value of the candidate's warhead against the chooser's [armor class](/reference/enums/armor/), as a fraction, so `100%` counts as `1`. The warhead is the one on the weapon the candidate would use against the chooser. A candidate with no such weapon, or whose weapon has no warhead, adds nothing to this term.

The coefficient comes from the type of the object doing the choosing, never from the candidate's type.

A positive value draws fire toward candidates that can hurt the chooser, except a candidate that is already targeting the chooser. For that candidate the term is subtracted instead of added. Of two otherwise identical candidates, the one targeting something else outscores the chooser's attacker by twice the term, so a positive coefficient steers the chooser away from whatever is attacking it.

:::caution[An explicit `0` does not last]
A `0` written on a type is replaced by [`TargetEffectivenessCoefficientDefault`](/keys/targeteffectivenesscoefficientdefault/) at the next rules layer, such as a map, whose copy of the type's section omits this key. To keep a type at zero while that default is not zero, write `0` in every layer that contains the section.
:::
