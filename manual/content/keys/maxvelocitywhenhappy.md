---
key: MaxVelocityWhenHappy
summary: The speed a wandering levitating unit must slow below before it can thrust again.
see_also: ["AccelerationProbability", "MaxVelocityWhenFollowing", "MaxVelocityWhenPissedOff", "Drag"]
when_omitted:
  kind: value
  value: "4"
---

A levitating unit with neither a target nor a destination wanders. While it coasts after a thrust, it may start a new thrust only once its speed has fallen below this figure. Below the figure, it rolls [`AccelerationProbability`](/keys/accelerationprobability/) each frame for a thrust in a random direction; at or above it, it keeps coasting.

The figure does not limit speed. A thrust is never cut short by it, so a thrust can carry the unit well past the figure. A figure above the speed a thrust ends at lets the unit thrust again at any point in its coast, and each new thrust adds to the motion the unit already has.

A wandering unit that slows below a hundredth of a lepton per frame comes to rest and reclaims its cell, whatever this figure is. At `0` or below, a wandering unit never thrusts while coasting. It comes to rest first, and thrusts again from rest if its mission allows, as `AccelerationProbability` describes.

[`MaxVelocityWhenFollowing`](/keys/maxvelocitywhenfollowing/) and [`MaxVelocityWhenPissedOff`](/keys/maxvelocitywhenpissedoff/) work the other way round. There, falling below the figure ends the coast and makes the unit brake.

[`Drag`](/keys/drag/) explains which objects use `[LEVITATION]` and why a file's `[LEVITATION]` section is read only when the file also has a `[General]` section.
