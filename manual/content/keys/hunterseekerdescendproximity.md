---
key: HunterSeekerDescendProximity
summary: Horizontal distance from its destination, in leptons, at which a hunter seeker starts diving onto its target.
see_also: [HunterSeekerDetonateProximity, HunterSeekerDescentSpeed, HunterSeekerAscentSpeed, HunterSeeker, "system:superweapons"]
when_omitted:
  kind: value
  value: "0"
---

A [hunter seeker](/systems/superweapons/#hunter-seeker) with a target starts its dive once it is closer than this to the point it is flying to. The distance is horizontal, measured flat across the map. The stock rules use `700`, about two and three-quarter cells.

During the dive the drone's flight level slides from its cruising level to the target's altitude in step with the remaining distance. At the edge of this range it is still the type's [`FlightLevel`](/keys/flightlevel/#scope-aircrafttype) above the ground, and on arrival it is the target's altitude. The level never goes below 10 leptons above the ground. [`HunterSeekerDescentSpeed`](/keys/hunterseekerdescentspeed/) sets how fast the drone actually drops, and within [`HunterSeekerDetonateProximity`](/keys/hunterseekerdetonateproximity/) it detonates.

Farther out than this, the drone clears terrain instead. It looks ahead along its heading as far as it travels in about ten frames. If the highest ground there is above the ground beneath it, it sets its flight level to that peak's height plus its `FlightLevel`. Because the flight level is measured from the ground under the drone, the drone ends up higher than the peak plus `FlightLevel` by the height of the ground under it.

At `0` the drone never dives. It keeps clearing terrain for the whole approach.
