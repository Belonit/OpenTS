---
key: AccelerationFactor
summary: The amount a vehicle's throttle climbs by on each movement step while it is speeding up.
see_also: ["Accelerates", "DeaccelerationFactor"]
when_omitted:
  kind: value
  value: ".03"
---

A vehicle's throttle runs from 0, stopped, to 1, its top speed. While the throttle is below the vehicle's target speed, each movement step adds this figure to it, up to the target. A vehicle takes one movement step per frame, and one more on a frame when it starts into a new cell. At `.03`, a vehicle needs 34 steps to climb from a standstill to full speed.

Only a vehicle with [`Accelerates=yes`](/keys/accelerates/) that the drive locomotor moves is affected, and not a [`Passive=yes`](/keys/passive/) one. The throttle does not climb while the vehicle is within [`SlowdownDistance`](/keys/slowdowndistance/) of its destination, is crushing something, or is sinking.

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
AccelerationFactor=.06 ; reaches full speed in 17 steps, half as many as at .03
```

:::caution[The braking figure is on a different scale]
This figure is added to the throttle as written. [`DeaccelerationFactor`](/keys/deaccelerationfactor/) is multiplied by the vehicle's top speed before it is subtracted. Writing the same value in both keys does not give a vehicle equal acceleration and braking.
:::
