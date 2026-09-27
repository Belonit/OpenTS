---
key: Accelerates
summary: Makes a driving vehicle ease up to speed and brake as it nears its destination.
see_also: ["AccelerationFactor", "DeaccelerationFactor", "SlowdownDistance"]
when_omitted:
  kind: value
  value: "yes"
---

Only the drive locomotor reads the flag. A type moved by any other [`Locomotor=`](/keys/locomotor/) gets its speed from that locomotor, whatever this flag says.

With `Accelerates=no`, the vehicle moves at its target speed from the first step and does not brake as it nears its destination. The target speed depends on the terrain of the cell the vehicle is entering, and slopes and damage change it.

With `Accelerates=yes`, the vehicle's speed changes toward the target speed a step at a time. [`AccelerationFactor`](/keys/accelerationfactor/) sets how fast it climbs and [`DeaccelerationFactor`](/keys/deaccelerationfactor/) how fast it falls. Braking begins once the vehicle is within [`SlowdownDistance`](/keys/slowdowndistance/) of its destination.

A ramped vehicle that other vehicles follow, such as a locomotive pulling cars, copies its speed onto every vehicle behind it on each step.

The ramping skips a [`Passive=yes`](/keys/passive/) vehicle. With the flag set, a passive vehicle does not ramp its own speed. While it follows a ramped vehicle, it moves at that vehicle's speed. With `Accelerates=no`, a passive vehicle moves at its target speed like any other.

While it is crushing something, a ramped vehicle moves at no more than a fifth of its top speed. A vehicle with `Accelerates=no` does not slow down to crush and keeps its target speed.
