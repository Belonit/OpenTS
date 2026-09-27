---
key: SlowdownDistance
summary: How far short of its destination an object begins slowing down, in leptons.
see_also: ["Accelerates", "DeaccelerationFactor", "IsDropship"]
when_omitted:
  kind: value
  value: "500"
---

A driven vehicle with [`Accelerates=yes`](/keys/accelerates/) and an aircraft both start to slow down once they are within this distance of their destination. The value is in leptons, and a cell is 256 leptons across. The default of `500` is a little under two cells, and `2000` is nearly eight.

```ini title="rules.ini"
[MYDROP] ; an AircraftType registered in [AircraftTypes]
SlowdownDistance=2000
```

A vehicle with `Accelerates=yes` brakes from the moment it comes within the distance. [`DeaccelerationFactor`](/keys/deaccelerationfactor/) sets how hard it brakes.

An aircraft throttles down in proportion to the distance left. When half this distance remains, it heads for half speed, and its speed moves toward that figure by a tenth of full speed each frame. Below a tenth of full speed, it holds a tenth until it is within a third of a cell, then stops. A hunter-seeker does not slow down this way, and an aircraft making a strafing run with ammunition left keeps full speed.

A dropship ([`IsDropship=yes`](/keys/isdropship/)) also uses the distance on its way in:

- Its nose starts to tilt as soon as it comes within the distance. The tilt reaches the full [`PitchAngle`](/keys/pitchangle/) once four tenths of the distance is covered, and holds from there.
- Its target cruising height drops to a third of its [`FlightLevel`](/keys/flightlevel/#scope-aircrafttype) the moment it crosses the distance, and the dropship descends toward that height. The height does not ease down across the distance.
