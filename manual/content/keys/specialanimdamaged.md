---
key: SpecialAnimDamaged
summary: The animation the first special slot runs while the structure is damaged.
see_also: ["SpecialAnim", "ConditionYellow"]
when_omitted:
  kind: inherited
  note: The animation SpecialAnim names.
---

`SpecialAnimDamaged=` names the animation that the first special slot runs in place of [`SpecialAnim`](/keys/specialanim/) while the structure's health is at or below [`ConditionYellow`](/keys/conditionyellow/).

A service depot and a storage structure always [start this slot](/keys/specialanim/#what-starts-a-special-animation) with the `SpecialAnim` name, whatever their health. The exception is a [`SpecialAnimPoweredLight=yes`](/keys/specialanimpoweredlight/) slot that is created when the house rechecks its power at full power. It starts with the name that matches the structure's health.

Otherwise the damaged name replaces the healthy one only when the structure's running animations switch form, such as after a damage or repair step. [The damaged form](/systems/building-animations/#the-damaged-form) lists the switches.

Setting only `SpecialAnimDamaged=` leaves a depot's first slot empty through every repair. On a [`SiloDamage=yes`](/keys/silodamage/) structure it crashes the game.
