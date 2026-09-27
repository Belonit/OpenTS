---
key: SpotlightSpeed
summary: Turn rate a spotlight beam builds toward, in radians per frame.
see_also: [SpotlightAcceleration, SpotlightAngle, HasSpotlight]
when_omitted:
  kind: value
  value: ".05"
---

`SpotlightSpeed` is the top turn rate of a sweeping spotlight, in radians per frame. Only a structure whose type sets [`HasSpotlight=yes`](/keys/hasspotlight/) has a beam.

A sweeping beam speeds up by [`SpotlightAcceleration`](/keys/spotlightacceleration/) each frame, in either direction, until its rate reaches this value. The rate is checked before each increase, so the final rate can exceed this value by up to one acceleration step. With both keys at their built-in values, the rate settles at `.055`.

A beam [set to circle its structure](/mapping/actions/taction-change-spotlight-behavior/) turns at four times this value every frame from the start. It uses neither `SpotlightAcceleration` nor [`SpotlightAngle`](/keys/spotlightangle/). At the `.015` the shipped rules set, a circling beam completes a turn in about 105 frames.

```ini title="rules.ini"
[General]
SpotlightSpeed=.03  ; twice the .015 the shipped rules set
```
