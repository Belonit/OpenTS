---
key: RollAngle
summary: The angle in degrees an aircraft banks by while it is turning.
see_also: ["PitchAngle", "PitchSpeed"]
when_omitted:
  kind: value
  value: "30"
---

`RollAngle` sets how far an aircraft banks while it turns. The value is in degrees. It affects only a type that flies with the aircraft (Flyer) [`Locomotor`](/keys/locomotor/).

An aircraft banks while it is off the ground, its throttle is above [`PitchSpeed`](/keys/pitchspeed/), and the direction it faces is turning. A clockwise turn banks it one way and a counter-clockwise turn the other. It levels out as soon as the turn finishes.

An [`IsDropship=yes`](/keys/isdropship/) type never banks. An aircraft destroyed in the air does not bank either; it tumbles sideways as it falls.

:::caution[Writing `-1` is the same as leaving the key out]
`RollAngle=-1` leaves the previous value in place, which is 30 degrees unless an earlier rules file changed it. Write `RollAngle=0` to make a type turn flat.
:::
