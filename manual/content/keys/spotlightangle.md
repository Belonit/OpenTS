---
key: SpotlightAngle
summary: Width of the arc a sweeping spotlight covers before reversing, in radians.
see_also: [SpotlightSpeed, SpotlightAcceleration, HasSpotlight]
when_omitted:
  kind: value
  value: "20"
---

`SpotlightAngle` sets how wide a sweeping spotlight swings. The beam starts pointing straight ahead of its structure and turns to one side about a pivot that [`SpotlightMovementRadius`](/keys/spotlightmovementradius/) places behind the structure. Once it has turned past half this angle, it slows by [`SpotlightAcceleration`](/keys/spotlightacceleration/) each frame until it stops, then turns back. It does the same on the other side, so the sweep is centered on the direction the structure faces.

The beam only starts slowing after it passes the half angle, so the sweep is wider than this value. The overshoot grows with [`SpotlightSpeed`](/keys/spotlightspeed/) and shrinks as `SpotlightAcceleration` rises. The angle is also measured at the pivot, so the beam covers a still wider angle as seen from the structure. With the shipped rules, the beam turns about 34 degrees about its pivot, which is about 90 degrees as seen from the structure.

```ini title="rules.ini"
[General]
SpotlightAngle=1.05  ; an arc of about sixty degrees before the overshoot
```

Only a structure whose type sets [`HasSpotlight=yes`](/keys/hasspotlight/) has a beam. The angle applies only while the beam sweeps. A beam [set to circle its structure or follow a target](/mapping/actions/taction-change-spotlight-behavior/) does not use it.

:::caution[Write the angle in radians]
The value is not converted from degrees. The shipped rules set `SpotlightAngle=.5`, a little under thirty degrees before the overshoot. A value above about 12.6 sends the beam more than a full circle in each direction before it turns back. The built-in value of `20`, used when no rules file sets the key, is one of these.
:::
