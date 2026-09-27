---
key: SpecialAnimTwo
summary: The animation the structure runs in its second special slot.
see_also: ["SpecialAnim", "SpecialAnimTwoDamaged", "SpecialAnimTwoX", "SpecialAnimTwoY", "SpecialAnimTwoYSort", "SpecialAnimTwoZAdjust", "SpecialAnimTwoPowered", "SpecialAnimTwoPoweredLight", "SpecialAnimThree", "UnitRepair", "FirestormWall"]
when_omitted:
  kind: value
  value: ""
---

On a [`UnitRepair=yes`](/keys/unitrepair/) service depot, the second special slot is the middle stage of the repair sequence. The depot creates this animation when the [`SpecialAnim`](/keys/specialanim/) animation plays to its end, if the depot is still on its repair mission and in contact with the visiting vehicle, and stops it when the visit ends. [A service depot](/keys/specialanim/#a-service-depot) covers the whole sequence.

If `SpecialAnim=` is empty, names no registered animation, or names one that loops, nothing in the first slot plays to its end, so the repair sequence never reaches this animation.

Other structures use the slot differently:

- A [`FirestormWall=yes`](/keys/firestormwall/) section runs the [`FirestormIdleAnim`](/keys/firestormidleanim/) animation in this slot at random moments while its house's firestorm is up. That animation does not use this name. If this name is set, damage or repair that moves the section across [`ConditionYellow`](/keys/conditionyellow/) while the idle animation runs replaces it with this slot's healthy or damaged animation.
- A [`SiloDamage=yes`](/keys/silodamage/) structure's fill indicator uses only the first special slot.
- Any structure can run this animation through [a powered light](/keys/specialanim/#a-powered-light-on-any-structure).

[Building animations](/systems/building-animations/) covers the offset, draw-order and power settings the slot shares with the other slots.
