---
key: ProximityDistance
summary: How close a levitating unit must be to what it is heading for before it drifts instead of thrusting.
see_also: ["IntentionalDriftVelocity", "IntentionalDeacceleration", "MaxVelocityWhenFollowing", "MaxVelocityWhenPissedOff"]
when_omitted:
  kind: value
  value: "1.5"
---

Within this distance of its target or destination, a stopped levitating unit drifts toward it at [`IntentionalDriftVelocity`](/keys/intentionaldriftvelocity/) instead of thrusting. The distance is in cells, measured flat from the unit's center to the center of the target or destination; height does not count. A unit whose target is an infantry, vehicle, aircraft or structure on the map steers at that target. Otherwise it steers at its destination.

During a thrust or a coast, a unit that comes within this distance of what it steers at brakes at [`IntentionalDeacceleration`](/keys/intentionaldeacceleration/). It also brakes farther out whenever a coast slows below [`MaxVelocityWhenPissedOff`](/keys/maxvelocitywhenpissedoff/) or [`MaxVelocityWhenFollowing`](/keys/maxvelocitywhenfollowing/). During a thrust, the unit also brakes once its destination comes within the distance, even while it steers at a target farther away. Once it has stopped, it drifts if what it steers at is within the distance, and thrusts toward it again otherwise.

The unit arrives when it is within half a cell of its target or destination, and all of its motion stops at once. `ProximityDistance` therefore sets the outer edge of the band in which the unit drifts toward its target or destination. The inner edge is half a cell. At `3`, a thrusting or coasting unit brakes as soon as it comes within three cells, and if it stops within three cells it drifts the rest of the way in. At `0.5` or less there is no band: the unit never drifts toward its target or destination, and it arrives only when it happens to stop within half a cell.

[`Drag`](/keys/drag/) covers which objects read this section and the `[General]` section a file must contain for any of it to be read at all.
