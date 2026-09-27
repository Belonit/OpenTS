---
key: HunterSeekerDetonateProximity
summary: Horizontal distance from its destination, in leptons, at which a hunter seeker detonates.
see_also: [HunterSeekerDescendProximity, C4Warhead, HunterSeeker, "system:superweapons"]
when_omitted:
  kind: value
  value: "0"
---

A [hunter seeker](/systems/superweapons/#hunter-seeker) detonates on the first frame it is closer than this to its target, measured flat across the map. The stock rules use `150`, about three-fifths of a cell. At `0` the drone never detonates on its target.

Detonation is tested before the dive. A value at or above [`HunterSeekerDescendProximity`](/keys/hunterseekerdescendproximity/) therefore detonates the drone before it reaches the dive range, so it never dives.

Detonation uses the drone's Primary weapon, or its [`Elite`](/keys/elite/) weapon once the drone is elite. The weapon's [`Damage`](/keys/damage/#scope-weapontype) is applied three times through its warhead:

- the target takes it, credited to the drone;
- the drone takes it, credited to no one;
- an explosion at the drone's position deals it to nearby objects, credited to no one.

Give every drone type a Primary weapon. A drone without one crashes the game when it detonates.

The detonation also makes a flash of light sized by the same damage. The flash uses [`C4Warhead`](/keys/c4warhead/), not the weapon's warhead, so it appears only if `C4Warhead` names a warhead with [`Bright=yes`](/keys/bright/#scope-warheadtype).

A drone that leaves the playable area is removed. Before removal it applies the same weapon's damage to its target once, whatever this setting.
