---
key: ActiveAnimTwoPoweredLight
summary: Whether the second active slot's animation is destroyed and recreated with its house's power.
see_also: ["ActiveAnimTwo", "ActiveAnimTwoPowered", "system:power"]
when_omitted:
  kind: value
  value: "no"
---

`ActiveAnimTwoPoweredLight=yes` removes the [`ActiveAnimTwo`](/keys/activeanimtwo/) animation when its house rechecks its power and is short, and creates it again when a recheck finds full power. Only some structures remove the animation; [Power](/systems/building-animations/#power) covers which. Despite its name, the flag does not light or tint anything.

The flag takes effect only beside [`ActiveAnimTwoPowered=no`](/keys/activeanimtwopowered/). While `ActiveAnimTwoPowered` is `yes`, its default, the animation freezes during a shortage and this flag is ignored.

Each time the house rechecks its power at full power, it creates the animation in the slot if the slot is empty. That includes an animation that played to its end.

Three events can start the animation again during a shortage, and it then runs until the next recheck removes it:

- A repair step starts it if the slot is empty, unless an exclusive turret is charging or charged.
- An [upgrade](/keys/upgrades/) installed on a structure below maximum strength starts it if the slot is empty.
- On a [`TurretAnimIsExclusive=yes`](/keys/turretanimisexclusive/) structure, the turret dropping its charge starts it. A turret that is charging or charged drops its charge when its house falls short of power.
