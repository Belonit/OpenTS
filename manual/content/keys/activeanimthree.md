---
key: ActiveAnimThree
summary: The animation the structure runs in its third active slot.
see_also: ["ActiveAnim", "ActiveAnimThreeDamaged", "ActiveAnimThreeX", "ActiveAnimThreeY", "ActiveAnimThreeYSort", "ActiveAnimThreeZAdjust", "ActiveAnimThreePowered", "ActiveAnimThreePoweredLight"]
when_omitted:
  kind: value
  value: ""
---

`ActiveAnimThree=` names the animation, registered in `[Animations]`, that the structure runs in its third active slot.

The slot starts when the structure comes online, and empties when a non-looping animation plays to its end. If the slot is empty, a repair step or an upgrade plug installed on a structure below maximum strength starts it again. So does the house rechecking its power at full power, when the slot sets [`ActiveAnimThreePowered=no`](/keys/activeanimthreepowered/) and [`ActiveAnimThreePoweredLight=yes`](/keys/activeanimthreepoweredlight/). [When the slot runs](/keys/activeanim/#when-the-slot-runs) gives the full rules.

No structure flag starts or stops the third slot. [`SensorArray`](/keys/sensorarray/) and [`UnitRepair`](/keys/unitrepair/) affect only slot one, and [`TurretAnimIsExclusive`](/keys/turretanimisexclusive/) affects only slot two. [Building animations](/systems/building-animations/) covers the offset, draw-order biases and damaged form that all four active slots share.

A type with six or more [`Upgrades=`](/keys/upgrades/) reads its `PowerUp6` art settings into this slot and lets its sixth plug take the slot over. [The upgrade slots and the active slots share one array](/systems/building-animations/#the-upgrade-slots-and-the-active-slots-share-one-array) covers what that replaces.
