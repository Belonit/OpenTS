---
key: SpotlightAcceleration
summary: Radians per frame by which a sweeping spotlight's turn rate rises and falls.
see_also: [SpotlightSpeed, SpotlightAngle, HasSpotlight]
when_omitted:
  kind: value
  value: ".005"
---

This value sets how quickly a sweeping spotlight speeds up and slows down. It controls two things: how briskly the beam starts each sweep, and how far it coasts past the edge of its arc before it turns back. A smaller value gives a gentler start and a longer overshoot.

Within its arc, the beam's turn rate rises by this amount each frame until it reaches [`SpotlightSpeed`](/keys/spotlightspeed/). The edge of the arc lies half of [`SpotlightAngle`](/keys/spotlightangle/) to either side. Once the beam passes it, the turn rate falls by this amount each frame. The beam reverses when the rate reaches zero.

```ini title="rules.ini"
[General]
SpotlightAcceleration=.001  ; a gentler ramp than the .0025 the shipped rules set
```

Only a structure whose type sets [`HasSpotlight=yes`](/keys/hasspotlight/) casts a beam. A beam [set to circle its structure or follow a target](/mapping/actions/taction-change-spotlight-behavior/) does not use this value.
