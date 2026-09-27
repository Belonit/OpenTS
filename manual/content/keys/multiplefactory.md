---
key: MultipleFactory
summary: The build-time multiplier each factory past the first applies to production of its category.
when_omitted:
  kind: value
  value: "1"
---

Every factory past the first that a house owns for a category multiplies that category's build times by `MultipleFactory`. The house counts every structure whose [`Factory=`](/keys/factory/) names the category, whether it is switched on or not, and [`MultipleFactoryCap`](/keys/multiplefactorycap/) limits how many count. The build time is rounded down to a whole game frame after each multiplication.

A value below `1` shortens build times: at `0.8`, two factories build in about 80% of the time and three in about 64%. A value of `1` changes nothing, and a value above `1` makes each extra factory lengthen build times. A value of `0` or below turns the adjustment off.

[More than one factory](/systems/production/#more-than-one-factory) shows where this multiplier falls among the other build-time adjustments.
