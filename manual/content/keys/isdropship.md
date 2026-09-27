---
key: IsDropship
summary: Flies an aircraft as a heavy transport that raises its nose on approach instead of banking.
see_also: ["SlowdownDistance", "PitchAngle", "FlightLevel", "Dock"]
when_omitted:
  kind: value
  value: "no"
---

The flag changes how an aircraft that uses the flyer [`Locomotor`](/keys/locomotor/) lands, how it is drawn, and where it goes to unload.

In normal flight it never banks into a turn and does not take the nose-down attitude other aircraft hold at speed. Instead, it tilts the opposite way, nose up, as it approaches its destination. The tilt starts when it comes within [`SlowdownDistance`](/keys/slowdowndistance/) of the destination and reaches the full [`PitchAngle`](/keys/pitchangle/) when 60% of that distance remains. After touchdown it levels out by 0.02 radians per frame and is drawn tilted until it is level. An ordinary aircraft on the ground is always drawn level. A dropship destroyed in the air tumbles like any other aircraft, as [`PitchAngle`](/keys/pitchangle/) describes.

Within [`SlowdownDistance`](/keys/slowdowndistance/) of its destination it also descends toward a cruising height of one third of its [`FlightLevel`](/keys/flightlevel/#scope-aircrafttype). When it comes below 300 leptons on landing, the `DROPLAND` animation plays on the ground beneath it. A dropship that is also a carryall plays `DROPLAND` in place of the carryall's `CARYLAND`.

It does not bob up and down in flight, and its shadow is drawn flat instead of following the slope of the ground beneath it.

While unloading, a dropship that is airborne and has no destination picks a place to land. It takes one of its owner's buildings of the first [`Dock`](/keys/dock/) type that has a building willing to take it, normally the nearest one. If no listed type has such a building, it picks a clear landing zone instead.
