---
key: HunterSeekerAscentSpeed
summary: Leptons a hunter seeker climbs each frame once it is airborne.
see_also: [HunterSeekerEmergeSpeed, HunterSeekerDescentSpeed, HunterSeeker, "system:superweapons"]
when_omitted:
  kind: value
  value: "0"
---

While an airborne [hunter seeker](/systems/superweapons/#hunter-seeker) is below its flight level, it climbs this many leptons each frame, or the distance still to go if that is smaller. The stock rules use `40`, about a sixth of a cell a frame. The first climb off the ground uses [`HunterSeekerEmergeSpeed`](/keys/hunterseekeremergespeed/) instead.

A drone mostly climbs to clear high ground ahead of it. On its way to a target it raises its flight level when it sees higher ground along its heading, as [`HunterSeekerDescendProximity`](/keys/hunterseekerdescendproximity/) describes. This value sets how quickly it gains that height.

At `0` a drone that has left the ground never climbs further, however high the ground ahead of it.
