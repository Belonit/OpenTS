---
key: HunterSeekerDescentSpeed
summary: Leptons a hunter seeker drops each frame.
see_also: [HunterSeekerAscentSpeed, HunterSeekerEmergeSpeed, HunterSeekerDescendProximity, HunterSeeker, "system:superweapons"]
when_omitted:
  kind: value
  value: "0"
---

While an airborne [hunter seeker](/systems/superweapons/#hunter-seeker) is above its flight level, it drops this many leptons each frame. The stock rules use `50`, about a fifth of a cell a frame. At `0` a drone that still has strength never drops and holds whatever altitude it has reached. [`HunterSeekerDescendProximity`](/keys/hunterseekerdescendproximity/) sets the level the drone descends to.

The drop is limited only by the drone's height above the ground, not by the gap to its flight level. A value larger than that gap takes the drone below its flight level in one step, and the next frame's climb at [`HunterSeekerAscentSpeed`](/keys/hunterseekerascentspeed/) brings it back up.

A hunter seeker does not use the staged descent of an ordinary aircraft, which drops a twentieth of the remaining gap each frame, held between 20 and 50 leptons. This value is its whole descent rate.

A drone reduced to zero strength falls. Each frame it drops by this value and also by a fall that starts at one lepton and grows by one lepton every frame. When it reaches the ground it is destroyed with a 1000-damage blast through [`C4Warhead`](/keys/c4warhead/) at the landing point.
