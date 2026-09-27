---
key: HoverBoost
summary: Multiplier on the throttle ceiling of a hovering unit whose path continues straight ahead.
see_also: [HoverAcceleration, HoverBrake]
when_omitted:
  kind: value
  value: "1.3"
---

A value above `1` never raises a hover unit's top speed; its [`Speed=`](/keys/speed/#scope-aircrafttype) still fixes what full throttle is worth. A hover unit's throttle is the fraction of that speed it is using, and the drive caps the throttle at a ceiling. This value multiplies the ceiling while the next two steps of the unit's path point the same way, and the result is capped at full throttle.

On a straight run the ceiling is already full, so a value above `1` changes nothing there. Within a cell of the destination the ceiling is half of full, but the path has two more steps in the same direction there only if it doubles back. On ordinary moves a value above `1` therefore has no effect. While the unit turns, the ceiling is zero and no multiplier raises it. [`HoverBrake`](/keys/hoverbrake/) covers when the ceiling drops.

A value below `1` lowers the ceiling on every straight run, so the unit crosses open ground below its top speed.
