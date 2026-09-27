---
key: SpecialAnimThreePoweredLight
summary: Whether the third special slot's animation is destroyed and recreated with its house's power.
see_also: ["SpecialAnimThree", "SpecialAnimThreePowered", "SpecialAnim", "system:power"]
when_omitted:
  kind: value
  value: "no"
---

With `yes`, the [`SpecialAnimThree`](/keys/specialanimthree/) animation is removed while its house is short of power, and created again when the house has full power. The flag works only with [`SpecialAnimThreePowered=no`](/keys/specialanimthreepowered/) written beside it. While `SpecialAnimThreePowered` is `yes`, the animation freezes instead and this flag is ignored.

A shortfall removes the animation only on some structures; [Fields, fences and lights](/systems/power/#fields-fences-and-lights) says which.

Each time the house [rechecks its power](/systems/power/#when-the-tally-is-rebuilt) at full power, it creates the animation if the slot is empty. This starts the slot on any structure, including one that is not a service depot; [A powered light on any structure](/keys/specialanim/#a-powered-light-on-any-structure) covers that route. A non-looping animation plays again at each recheck.

The value is read only when the slot has an animation name from `SpecialAnimThree` or [`SpecialAnimThreeDamaged`](/keys/specialanimthreedamaged/). Write it in the art entry named after the structure's ObjectType ID, even when [`Image=`](/keys/image/) puts the animation names in another entry. [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) has the full table.

Despite its name, the flag does not tint or light anything.
