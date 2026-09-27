---
key: ActiveAnimThreePowered
summary: Whether the third active slot's animation freezes while its house is short of power.
see_also: ["ActiveAnimThree", "ActiveAnimThreePoweredLight", "system:power"]
when_omitted:
  kind: value
  value: "yes"
---

With `yes`, the [`ActiveAnimThree`](/keys/activeanimthree/) animation freezes on its current frame while its house is short of power, and resumes when the house has full power again. With `no`, a power shortfall does not freeze it.

A shortfall freezes the animation only on some structures; [Fields, fences and lights](/systems/power/#fields-fences-and-lights) says which. Switching the structure off and an [EMP pulse](/systems/emp-pulse/) can also freeze a `yes` animation, and [Power](/systems/building-animations/#power) covers when.

To remove the animation during a shortfall instead of freezing it, set `ActiveAnimThreePowered=no` and [`ActiveAnimThreePoweredLight=yes`](/keys/activeanimthreepoweredlight/).
