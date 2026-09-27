---
key: Acceleration
scope: levitation-controls
label: Levitation thrust
see_also: ["AccelerationDuration", "InitialBoost", "Drag", "AccelerationProbability"]
when_omitted:
  kind: value
  value: "0.5"
---

The figure is the speed a levitating unit gains on each frame of a thrust, in the direction the thrust is aimed. A thrust lasts [`AccelerationDuration`](/keys/accelerationduration/) frames. Speeds here are in leptons per frame, with 256 leptons to a cell and 15 frames to the second.

[`Drag`](/keys/drag/) is subtracted on each of those frames as well. A thrust that starts from rest therefore ends at a speed you can work out in advance: the [`InitialBoost`](/keys/initialboost/) it opens with, plus `AccelerationDuration × (Acceleration − Drag)`. The stock values give `1.5 + 20 × (0.5 − 0.05)`, or 10.5 leptons per frame. A thrust that starts while the unit is still moving adds to that motion instead, and on a different heading the two combine as vectors.

A thrust ends early when the unit comes within [`ProximityDistance`](/keys/proximitydistance/) of its target or destination. The unit then brakes, and the remaining frames of the thrust are lost.

Nothing caps the speed a thrust reaches. [`MaxVelocityWhenFollowing`](/keys/maxvelocitywhenfollowing/) and [`MaxVelocityWhenPissedOff`](/keys/maxvelocitywhenpissedoff/) decide when a coast ends, and [`MaxVelocityWhenHappy`](/keys/maxvelocitywhenhappy/) decides when a fresh thrust may begin. None of them limits how fast a thrust leaves the unit traveling, so a large figure here raises the unit's top speed without limit. Keep the speed a thrust builds under 256 leptons per frame along each map axis; otherwise the game can stop responding, as [`IntentionalDriftVelocity`](/keys/intentionaldriftvelocity/) explains.

[`Drag`](/keys/drag/) covers which objects read this section and the `[General]` section a file must contain for any of it to be read at all.
