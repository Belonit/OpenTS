---
key: SpecialAnimThreePowered
summary: Whether the third special slot's animation freezes while its house is short of power.
see_also: ["SpecialAnimThree", "SpecialAnimThreePoweredLight", "SpecialAnim", "system:power"]
when_omitted:
  kind: value
  value: "yes"
---

With `yes`, the [`SpecialAnimThree`](/keys/specialanimthree/) animation freezes on its current frame while its house is short of power, and resumes when the house has full power again. With `no`, a power shortfall does not freeze it.

A shortfall freezes the animation only on some structures; [Fields, fences and lights](/systems/power/#fields-fences-and-lights) says which. Switching the structure off and an [EMP pulse](/systems/emp-pulse/) can also freeze a `yes` animation, and [Power](/systems/building-animations/#power) covers when.

To remove the animation during a shortfall instead of freezing it, set `SpecialAnimThreePowered=no` and [`SpecialAnimThreePoweredLight=yes`](/keys/specialanimthreepoweredlight/).

The value is read only when the slot has an animation name from `SpecialAnimThree` or [`SpecialAnimThreeDamaged`](/keys/specialanimthreedamaged/). Write it in the art entry named after the structure's ObjectType ID, even when [`Image=`](/keys/image/) puts the animation names in another entry. [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) has the full table.
