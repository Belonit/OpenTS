---
key: SpecialAnimThree
summary: The animation the structure runs in its third special slot.
see_also: ["SpecialAnim", "SpecialAnimTwo", "SpecialAnimThreeDamaged", "SpecialAnimThreeX", "SpecialAnimThreeY", "SpecialAnimThreeYSort", "SpecialAnimThreeZAdjust", "SpecialAnimThreePowered", "SpecialAnimThreePoweredLight", "UnitRepair"]
when_omitted:
  kind: value
  value: ""
---

The value names an animation registered in `[Animations]`, which a [`UnitRepair=yes`](/keys/unitrepair/) service depot runs in its third special slot when a repair visit ends. [A service depot](/keys/specialanim/#a-service-depot) gives the whole sequence and the ways a visit can end.

Nothing in the repair cycle stops the third slot once it starts. A later visit starts its first-slot animation while the third is still running. A looping animation here therefore runs until the structure begins to be sold or is taken off the map.

Storing Tiberium in a [`SiloDamage=yes`](/keys/silodamage/) structure and raising a [`FirestormWall=yes`](/keys/firestormwall/) section never start the third slot. On any structure, including those, [`SpecialAnimThreePoweredLight=yes`](/keys/specialanimthreepoweredlight/) can start it. [Building animations](/systems/building-animations/) covers what the slot's companion settings do.
