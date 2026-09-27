---
key: DeaccelerationFactor
summary: How hard a vehicle brakes. Each frame its throttle drops by this figure times its top speed.
see_also: ["Accelerates", "AccelerationFactor", "SlowdownDistance"]
when_omitted:
  kind: value
  value: ".002"
---

The figure sets how hard a driving vehicle brakes. While the vehicle slows, its throttle drops each frame by this figure multiplied by the vehicle's top speed. In a frame where the vehicle finishes one cell and starts the next, the drop applies twice.

Only a vehicle with [`Accelerates=yes`](/keys/accelerates/) that is moved by the drive locomotor brakes this way, and a [`Passive=yes`](/keys/passive/) vehicle never does. No vehicle brakes while it backs into a refinery or drives out of a refinery or a war factory.

A vehicle slows in two situations:

- **Within [`SlowdownDistance`](/keys/slowdowndistance/) of its destination.** The throttle never drops below three tenths here. A vehicle whose throttle is already lower is raised to three tenths, so it arrives at no less than 0.3 of its top speed.
- **Whenever its throttle is above the throttle it has been told to hold.** The throttle drops to that level and no lower.

A vehicle that is crushing something does neither. Its throttle is set straight to 0.2, or to the throttle it has been told to hold when that is lower, so the three-tenths floor does not apply while it crushes.

The top speed used is the stored figure on the engine's 0-to-255 scale that [`Speed`](/keys/speed/#scope-aircrafttype) describes, so faster types brake harder from the same written figure. `Speed=6` stores 15, so at the default `.002` that vehicle sheds `.03` of its throttle per frame, the same step the default [`AccelerationFactor`](/keys/accelerationfactor/) adds. A limpet drone clamped to a vehicle lowers its top speed, and so its braking, too.
