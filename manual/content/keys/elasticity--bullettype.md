---
key: Elasticity
scope: bullettype
label: Projectile rebound damping
see_also: [Bouncy, Arcing]
when_omitted:
  kind: value
  value: ".75"
---

The fraction of its speed a projectile keeps when it rebounds from the surface it lands on. `0.5` keeps half, `0` leaves the projectile motionless where it landed, and a figure above `1` adds speed on every rebound. A projectile left motionless settles and detonates where it lies.

The rebound follows the slope of the cell the projectile lands in, so a projectile that lands on a ramp is deflected downhill.

Only a [`Bouncy=yes`](/keys/bouncy/) projectile rebounds and shows the effect. Every other projectile detonates on its first landing. The `Bouncy` page lists what else ends a bouncing projectile's flight.
