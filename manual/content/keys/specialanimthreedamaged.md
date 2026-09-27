---
key: SpecialAnimThreeDamaged
summary: The animation the third special slot runs while the structure is damaged.
see_also: ["SpecialAnimThree", "SpecialAnim", "ConditionYellow"]
when_omitted:
  kind: inherited
  note: The animation SpecialAnimThree names.
---

`SpecialAnimThreeDamaged=` names the animation that the third special slot runs in place of [`SpecialAnimThree`](/keys/specialanimthree/) while the structure's health is at or below [`ConditionYellow`](/keys/conditionyellow/).

A service depot always [starts this slot](/keys/specialanim/#a-service-depot) with the `SpecialAnimThree` name, whatever its health. The exception is a [`SpecialAnimThreePoweredLight=yes`](/keys/specialanimthreepoweredlight/) slot that is created when the house rechecks its power at full power. It starts with the name that matches the structure's health.

Otherwise the damaged name replaces the healthy one only when the structure's running animations switch form, such as after a damage or repair step. [The damaged form](/systems/building-animations/#the-damaged-form) lists the switches.

Setting only `SpecialAnimThreeDamaged=` leaves a depot's third slot empty at the end of every visit.
