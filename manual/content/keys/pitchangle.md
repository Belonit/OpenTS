---
key: PitchAngle
summary: The angle in degrees an aircraft drops its nose by while it is flying fast enough.
see_also: ["PitchSpeed", "RollAngle", "IsDropship"]
when_omitted:
  kind: value
  value: "20"
---

`PitchAngle` sets how far an aircraft tips its nose down in flight. The value is in degrees. It affects only a type that flies with the aircraft (Flyer) [`Locomotor`](/keys/locomotor/).

An ordinary aircraft pitches nose down while it is off the ground and its throttle is above [`PitchSpeed`](/keys/pitchspeed/). At or below that throttle it flies level. A [`HunterSeeker=yes`](/keys/hunterseeker/#scope-aircrafttype) type never pitches nose down in ordinary flight.

An aircraft destroyed in the air tumbles as it falls. While its throttle is above [`PitchSpeed`](/keys/pitchspeed/), `PitchAngle` is added to its forward tumble. This applies to every aircraft, including dropships and hunter-seekers.

## Dropships

An [`IsDropship=yes`](/keys/isdropship/) type ignores the throttle rule. It raises its nose by up to `PitchAngle` as it comes in to land. The tilt starts once the dropship is within [`SlowdownDistance`](/keys/slowdowndistance/) of its landing point, and grows until the dropship has covered four tenths of that distance. From there it holds at `PitchAngle`.

A dropship that is taking off or retreating is drawn without the tilt. After touching down, it levels off by about 1.15 degrees per frame, so the default 20 degrees takes 18 frames. It does not finish landing until it is level.

:::caution[Writing `-1` is the same as leaving the key out]
`PitchAngle=-1` leaves the previous value in place, which is 20 degrees unless an earlier rules file changed it. Write `PitchAngle=0` to make a type fly level.
:::
