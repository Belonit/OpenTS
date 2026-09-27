---
key: PlayerScatter
summary: Lets objects scatter on their own, including those a player commands.
see_also: ["Scatter", "Incoming"]
when_omitted:
  kind: value
  value: "no"
---

Scattering is the short move an object makes to get out of the way of a threat. An aircraft that scatters makes no such move; it takes up the mission it would choose when idle. Setting this to `yes` lets objects scatter in the three situations below, and lifts the refusal a player's infantry otherwise applies. Despite its name, it also affects computer-owned objects in the first and third situations. At `no`, other conditions in each list can still make an object scatter.

In each list, "earned the scatter ability" means the object is a veteran whose type lists the ability under [`VeteranAbilities=`](/keys/veteranabilities/), or an elite whose type lists it under `VeteranAbilities=` or [`EliteAbilities=`](/keys/eliteabilities/).

## After damage it may answer

An object that has just been hit and is allowed to answer the attacker scatters when **all of** these hold:

- it has no target;
- it has no destination;
- **any of:** this setting is `yes`, or the object has earned the scatter ability.

This applies to computer-owned and player-owned objects alike. [Retaliation](/systems/target-selection/#scattering-after-damage) covers when an allowed answer still leaves the object with no target.

## After damage it may not answer

An object that has just been hit and is not allowed to answer scatters when **all of** these hold:

- its mission sets [`Scatter=yes`](/keys/scatter/#scope-mission-behavior);
- it is not tethered to an object it is working with, such as the refinery it is docking at, the structure or transport it has just left, or a carryall coming to lift it;
- it is standing still;
- it has no target;
- it has no destination;
- it is not an aircraft;
- **any of:** its house is under computer control, this setting is `yes`, or the object has earned the scatter ability.

## When a threat is coming

When a cell is warned that a threat is coming, each occupant is told to scatter when **any of** these hold:

- an occupant of that cell is elite;
- the warning was raised as overriding;
- this setting is `yes`;
- the object has earned the scatter ability;
- the object's house has an IQ at or above [`[IQ] Scatter`](/keys/scatter/#scope-global-rules).

The first three conditions apply to every occupant of the cell. The last two are tested for each object, so one occupant can be told to scatter while its neighbor is not. An occupant told to scatter can still refuse, for example because of its mission or the [infantry refusal](#infantry-refusal) below.

## Infantry refusal

A soldier belonging to a player refuses to scatter unless **any of** these hold:

- this setting is `yes`;
- the soldier has earned the scatter ability;
- the scatter was forced and the soldier is standing still;
- the warning was overriding;
- the soldier belongs to a team.

Vehicles have no such refusal.

The object's mission can also refuse a scatter; [`Scatter`](/keys/scatter/#scope-mission-behavior) covers when. A vehicle's mission can refuse only a scatter that was not forced. A soldier's mission can also refuse a forced scatter while the soldier is moving. An aircraft's mission can refuse any scatter, forced or not.
