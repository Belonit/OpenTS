---
key: TurretSpins
summary: Makes a vehicle's turret rotate continuously instead of holding an aim.
see_also: ["Turret"]
when_omitted:
  kind: value
  value: "no"
---

Only a vehicle reads the flag. Its turret turns clockwise by one thirty-second of a circle every game frame, so it completes a turn every 32 frames. [`ROT`](/keys/rot/#scope-aircrafttype) does not change this speed.

Each step sets the turret's facing outright, replacing any aim given to it in the same frame. A spinning turret therefore never settles on a target.

The flag has an effect only with [`Turret=yes`](/keys/turret/). On any other vehicle the spin is neither drawn nor used for aiming.

No stock type sets the flag.
