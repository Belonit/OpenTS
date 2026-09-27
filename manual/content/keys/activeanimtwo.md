---
key: ActiveAnimTwo
summary: The animation the structure runs in its second active slot.
see_also: ["ActiveAnim", "ActiveAnimTwoDamaged", "ActiveAnimTwoX", "ActiveAnimTwoY", "ActiveAnimTwoYSort", "ActiveAnimTwoZAdjust", "ActiveAnimTwoPowered", "ActiveAnimTwoPoweredLight", "TurretAnimIsExclusive"]
when_omitted:
  kind: value
  value: ""
---

The value names one AnimType registered in `[Animations]`. A comma-separated list is read as a single name and matches nothing. [Building animations](/systems/building-animations/) covers when the structure fills and empties its active slots.

The second slot is the only one a charging turret can take over. On a [`TurretAnimIsExclusive=yes`](/keys/turretanimisexclusive/) structure, the animation is removed as the turret starts charging, and the slot stays empty while the turret is charging or charged. The animation starts again when the turret fires, or when it drops the charge because it lost its target, its house fell short of power, or the structure was switched off. Without that flag, a charging turret leaves this slot alone, and both animations run at once.

Two events start this slot's animation without checking the turret. If either happens while an exclusive turret is charging or charged, both animations run until the turret fires or drops its charge:

- An [upgrade](/keys/upgrades/) installed on a structure below maximum strength repairs it fully and starts every empty active slot.
- With [`ActiveAnimTwoPowered=no`](/keys/activeanimtwopowered/) and [`ActiveAnimTwoPoweredLight=yes`](/keys/activeanimtwopoweredlight/), each full-power recheck of the house starts this slot if it is empty.

The AnimType's [`LoopCount`](/keys/loopcount/) sets how many times the animation plays in the slot. When the last pass ends, the slot stays empty until an event starts it again. If the AnimType chains to another animation, that animation takes over the slot, and the slot empties only when the last animation in the chain ends.
