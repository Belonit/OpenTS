---
key: SpecialAnimTwoDamaged
summary: The animation the second special slot runs while the structure is damaged.
see_also: ["SpecialAnimTwo", "SpecialAnim", "ConditionYellow"]
when_omitted:
  kind: inherited
  note: The animation SpecialAnimTwo names.
---

The structure runs this animation in place of [`SpecialAnimTwo`](/keys/specialanimtwo/) while its attached animations are shown in their damaged form. [The damaged form](/systems/building-animations/#the-damaged-form) covers when the structure switches the whole set between forms.

A service depot always starts this slot with the healthy `SpecialAnimTwo` name, whatever its health. Apart from the powered-light case below, this animation appears only when the running set switches to the damaged form while the slot is running. That happens when the structure takes damage or receives a repair step while at or below [`ConditionYellow`](/keys/conditionyellow/), or when another slot is filled in its damaged form. The swap keeps the frame the animation had reached.

The one fill that starts this animation directly is the full-power fill of a slot with [`SpecialAnimTwoPowered=no`](/keys/specialanimtwopowered/) and [`SpecialAnimTwoPoweredLight=yes`](/keys/specialanimtwopoweredlight/), made while the structure is at or below `ConditionYellow`.
