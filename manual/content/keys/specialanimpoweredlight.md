---
key: SpecialAnimPoweredLight
summary: Whether the first special slot's animation is destroyed and recreated with its house's power.
see_also: ["SpecialAnim", "SpecialAnimPowered", "system:power"]
when_omitted:
  kind: value
  value: "no"
---

With `yes`, the [`SpecialAnim`](/keys/specialanim/) animation is removed while its house is short of power, and created again when the house has full power. The flag works only with [`SpecialAnimPowered=no`](/keys/specialanimpowered/) written beside it. While `SpecialAnimPowered` is `yes`, the animation freezes instead and this flag is ignored.

A shortfall removes the animation only on some structures; [Fields, fences and lights](/systems/power/#fields-fences-and-lights) says which.

Each time the house [rechecks its power](/systems/power/#when-the-tally-is-rebuilt) at full power, it creates the animation if the slot is empty. This starts the slot on any structure, including one that is not a service depot, storage structure or firestorm wall section; [A powered light on any structure](/keys/specialanim/#a-powered-light-on-any-structure) covers that route. A non-looping animation plays again at each recheck.

The value is read only when the slot has an animation name from `SpecialAnim` or [`SpecialAnimDamaged`](/keys/specialanimdamaged/). Write it in the art entry named after the structure's ObjectType ID, even when [`Image=`](/keys/image/) puts the animation names in another entry. [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) has the full table.

Despite its name, the flag does not tint or light anything.
