---
key: PitchSpeed
summary: The throttle an aircraft must be above before it pitches and banks.
see_also: ["PitchAngle", "RollAngle"]
when_omitted:
  kind: value
  value: ".25"
---

`PitchSpeed` is a throttle threshold. Throttle is the aircraft's current speed as a fraction of its top speed, from 0 to 1. Because it is a fraction, the same `PitchSpeed` means the same share of top speed whatever [`Speed=`](/keys/speed/#scope-aircrafttype) is.

Above the threshold, an airborne aircraft pitches its nose down by [`PitchAngle`](/keys/pitchangle/) and banks by [`RollAngle`](/keys/rollangle/) while it turns. At or below the threshold it is drawn level. `PitchSpeed=0` gives an aircraft its flying attitude as soon as it starts moving. A value of 1 or more keeps it level at every speed.

An [`IsDropship=yes`](/keys/isdropship/) type neither pitches nor banks this way. For a dropship, the threshold matters only after it is destroyed in the air. While its throttle is above the threshold, its `PitchAngle` is added to its tumble as it falls, as for any other aircraft. The stock dropship sets `.4`.
