---
key: SpecialAnimTwoPoweredLight
summary: Whether the second special slot's animation is destroyed and recreated with its house's power.
see_also: ["SpecialAnimTwo", "SpecialAnimTwoPowered", "SpecialAnim", "system:power"]
when_omitted:
  kind: value
  value: "no"
---

With `yes`, the [`SpecialAnimTwo`](/keys/specialanimtwo/) animation is removed while its house is short of power. Each time the house rechecks its power at full power, the animation is created again if the slot is empty. The value takes effect only beside [`SpecialAnimTwoPowered=no`](/keys/specialanimtwopowered/). With the default `SpecialAnimTwoPowered=yes`, the animation freezes instead and this value is ignored.

[Power](/systems/building-animations/#power) covers which structures lose the animation when power runs short. Switching the structure off or an EMP pulse does not remove it unless the house is also short of power.

Because every full-power recheck fills an empty slot, the animation runs on any structure of the type, even one that nothing else would start a special animation on. A finite animation that has played to its end therefore returns at the next recheck. [A powered light on any structure](/keys/specialanim/#a-powered-light-on-any-structure) covers this.

The slot's animation names come from a different art entry when the structure sets [`Image=`](/keys/image/); [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) covers the split.
