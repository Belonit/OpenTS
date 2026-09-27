---
key: ConditionYellowSparkingProbability
summary: Chance each frame that a damaged object starts throwing sparks.
see_also: [ConditionRedSparkingProbability, ConditionYellow, DamageParticleSystems]
when_omitted:
  kind: value
  value: ".01"
---

While an object's strength is below [`ConditionYellow`](/keys/conditionyellow/) but not below [`ConditionRed`](/keys/conditionred/), this is the chance each frame that it starts throwing damage sparks. The value is a fraction: `0` never starts sparks, and `1` or more starts them on practically every frame the chance is drawn.

Below `ConditionRed`, [`ConditionRedSparkingProbability`](/keys/conditionredsparkingprobability/) applies instead. At or above `ConditionYellow` no chance is drawn, so an object that has not dropped below `ConditionYellow` never sparks, whatever this value is. When the two thresholds are equal, as their engine defaults are, this value never applies.

[`ConditionRedSparkingProbability`](/keys/conditionredsparkingprobability/) lists the other conditions sparks need and how often a new spark system can start.
