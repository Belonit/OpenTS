---
key: SpecialAnimTwoPowered
summary: Whether the second special slot's animation freezes while its house is short of power.
see_also: ["SpecialAnimTwo", "SpecialAnimTwoPoweredLight", "SpecialAnim", "system:power"]
when_omitted:
  kind: value
  value: "yes"
---

With `yes`, the [`SpecialAnimTwo`](/keys/specialanimtwo/) animation freezes on its current frame while the structure is without power, stays on screen, and resumes when power returns. With `no`, it keeps playing, unless [`SpecialAnimTwoPoweredLight=yes`](/keys/specialanimtwopoweredlight/) removes it instead.

[Power](/systems/building-animations/#power) covers which structures freeze when their house is short of power, and the power cursor, trigger action and EMP pulse that freeze an animation on one structure.

The slot's animation names come from a different art entry when the structure sets [`Image=`](/keys/image/); [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) covers the split.
