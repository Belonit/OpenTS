---
key: Trainable
summary: Allows an object of this type to accumulate experience from kills and receive veterancy-crate promotions.
see_also: ["system:veterancy"]
when_omitted:
  kind: context-dependent
  note: "`yes` for AircraftTypes, InfantryTypes, and UnitTypes; BuildingTypes start at `no` and must set the key to earn from kills or receive a veterancy-crate promotion."
---

When an object is destroyed, the object that dealt the fatal damage earns [experience](/systems/veterancy/) only if its type is `Trainable=yes`. An object of a `Trainable=no` type never gains experience, however much it destroys.

A veterancy crate also checks the key. It promotes every `Trainable=yes` object on the ground within [`CrateRadius`](/keys/crateradius/) of the crate, whoever owns it, so enemy and neutral objects rise alongside the collector's own. An object of a `Trainable=no` type is skipped and keeps any rank it already holds.

Other ways of giving a rank ignore this key. An object promoted by deploying from a promoted vehicle, by a reinforcement's [`VeteranLevel`](/keys/veteranlevel/), or by an armory holds that rank and everything it unlocks, whatever this setting says.
