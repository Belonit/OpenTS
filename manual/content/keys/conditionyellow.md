---
key: ConditionYellow
summary: The fraction of maximum strength at or below which an object counts as damaged.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: ".5"
---

At or below this fraction of its maximum strength, an object's health bar turns yellow. [`ConditionRed`](/keys/conditionred/) sets the lower fraction at which it turns red.

Either threshold can be written as a fraction or a percentage. The retail rules use percentages:

```ini title="rules.ini"
[AudioVisual]
ConditionYellow=50%
ConditionRed=25%
```

The same threshold changes several behaviors at or below it:

- A structure switches to its damaged artwork, and each animation it starts uses its damaged form.
- A driven vehicle moves at three quarters of its speed.
- An aircraft owned by a computer house breaks off to look for a repair bay, provided the house has at least 100 credits.
- [Self-healing](/systems/repair/#self-healing) stops once an object passes this fraction, unless [`SelfHealCap`](/keys/selfhealcap/) or a type's [`SelfHealingCap`](/keys/selfhealingcap/) sets another ceiling.
- Between this fraction and `ConditionRed`, [`ConditionYellowSparkingProbability`](/keys/conditionyellowsparkingprobability/) sets the chance of damage sparks.

An object's damage smoke goes out once repair or healing takes it above this fraction.

A power shortfall damages only structures above this fraction, so it [wears a base down](/systems/power/#the-structure-damage-tick) to this fraction and stops there. Raising the value leaves structures stronger after a long shortfall; lowering it lets a shortfall take them closer to destruction.
