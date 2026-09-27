---
key: HunterSeekerEmergeSpeed
summary: Leptons a hunter seeker climbs each frame while it is still lifting off.
see_also: [HunterSeekerAscentSpeed, HunterSeekerDescentSpeed, HunterSeeker, "system:superweapons"]
when_omitted:
  kind: value
  value: "0"
---

A [hunter seeker](/systems/superweapons/#hunter-seeker) lifts off as soon as it has somewhere to fly. Each frame of the lift-off it climbs this many leptons, or the distance left to its flight level if that is smaller. The stock rules use `6`, about a fortieth of a cell a frame.

Lift-off ends when the drone reaches its flight level. Every later climb uses [`HunterSeekerAscentSpeed`](/keys/hunterseekerascentspeed/) instead.

The drone cannot detonate on its target until lift-off has ended. At `0` it never gains height, so it never finishes lifting off and never detonates.
