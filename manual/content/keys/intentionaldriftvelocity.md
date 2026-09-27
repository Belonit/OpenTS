---
key: IntentionalDriftVelocity
summary: The fixed speed of a levitating unit's slow drift toward its target or back to the center of its cell.
see_also: ["ProximityDistance", "MaxBlockCount", "Acceleration", "InitialBoost"]
when_omitted:
  kind: value
  value: "0.3"
---

A drift sets a levitating unit moving at this speed, and the unit loses none of it to [`Drag`](/keys/drag/) or braking while the drift lasts. A drift cancels any thrust in progress. A drift aimed at a point never overshoots it: when the point is closer than one frame's drift along a map axis, the unit moves only as far as the point along that axis.

A unit drifts in three cases:

1. It has stopped within [`ProximityDistance`](/keys/proximitydistance/) of its target or destination, but more than half a cell from it. The drift continues until the unit is within half a cell, where it stops. If the target moves back out of `ProximityDistance`, the unit thrusts toward it instead.
2. A move is blocked. The unit drifts back to the center of its cell.
3. It has returned to the center of its cell after a blocked move and has a target or destination. It drifts out of the cell toward it. Once it enters the next cell, it carries on as after a thrust: it coasts under [`Drag`](/keys/drag/), and brakes as soon as its speed is below [`MaxVelocityWhenPissedOff`](/keys/maxvelocitywhenpissedoff/) with a target, or [`MaxVelocityWhenFollowing`](/keys/maxvelocitywhenfollowing/) with only a destination. With every `[LEVITATION]` key omitted, the drift is slower than both figures, so the unit brakes at once. A unit with nothing to head for coasts instead of drifting out.

The figure is in leptons per frame, with 256 leptons to a cell and 15 frames to the second. At `12`, a drift covers about two thirds of a cell per second.

:::caution[Set IntentionalDriftVelocity to 1.5 or more]
A unit's position changes only in whole leptons along each of the map's two axes, and any fraction is dropped every frame. A drift below 1 lepton per frame therefore never moves the unit, and a drift below about 1.42 does not move it in some directions. A unit whose drift cannot move stays where it is: short of its destination, or off the center of its cell after a blocked move, where it never recovers. The value used when this key is omitted is below 1.
:::

:::danger[Keep every levitation speed below 256 leptons per frame]
A levitating unit that moves more than 256 leptons along either map axis in one frame can land two cells from where it started. The check for entering that cell then never finishes, and the game stops responding. The check sees only one frame's movement, so a long move order is not a risk. The speed is split between the two axes, so the direction of travel decides whether a given speed crosses the limit. Nothing clamps this figure or the speed a thrust builds.
:::

[`Drag`](/keys/drag/) explains which objects use `[LEVITATION]` and why a file's `[LEVITATION]` section is read only when the file also has a `[General]` section.
