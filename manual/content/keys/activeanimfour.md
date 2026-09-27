---
key: ActiveAnimFour
summary: The animation the structure runs in its fourth active slot.
see_also: ["ActiveAnim", "ActiveAnimFourDamaged", "ActiveAnimFourX", "ActiveAnimFourY", "ActiveAnimFourYSort", "ActiveAnimFourZAdjust", "ActiveAnimFourPowered", "ActiveAnimFourPoweredLight"]
when_omitted:
  kind: value
  value: ""
---

`ActiveAnimFour=` names the animation, registered in `[Animations]`, that the structure runs in its fourth active slot.

The slot starts when the structure comes online, and empties when a non-looping animation plays to its end. If the slot is empty, a repair step or an upgrade plug installed on a structure below maximum strength starts it again. So does the house rechecking its power at full power, when the slot sets [`ActiveAnimFourPowered=no`](/keys/activeanimfourpowered/) and [`ActiveAnimFourPoweredLight=yes`](/keys/activeanimfourpoweredlight/). [When the slot runs](/keys/activeanim/#when-the-slot-runs) gives the full rules.

No structure flag starts or stops the fourth slot. [`SensorArray`](/keys/sensorarray/) and [`UnitRepair`](/keys/unitrepair/) affect only slot one, and [`TurretAnimIsExclusive`](/keys/turretanimisexclusive/) affects only slot two. [Building animations](/systems/building-animations/) covers the offset, draw-order biases and damaged form that all four active slots share.

A type with seven or more [`Upgrades=`](/keys/upgrades/) reads its `PowerUp7` art settings into this slot and lets its seventh plug take the slot over. [The upgrade slots and the active slots share one array](/systems/building-animations/#the-upgrade-slots-and-the-active-slots-share-one-array) covers what that replaces.
