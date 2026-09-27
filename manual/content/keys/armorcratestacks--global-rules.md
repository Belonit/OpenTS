---
key: ArmorCrateStacks
scope: global-rules
label: Let armor crates stack
summary: Lets an armor crate upgrade an object that an earlier armor crate already upgraded.
see_also: [FirepowerCrateStacks, "system:crates"]
when_omitted:
  kind: value
  value: "no"
---

An armor crate multiplies the armor multiplier of objects on the ground within [`CrateRadius`](/keys/crateradius/) by the `Armor` value in `[Powerups]`. `ArmorCrateStacks` decides what happens to objects an earlier armor crate already upgraded.

At `no`, an armor crate upgrades only objects whose armor multiplier is still exactly `1`. An armor result drawn by a collector that is already upgraded turns into money instead.

At `yes`, every armor crate multiplies the armor multiplier again, and the armor result is no longer turned into money for an upgraded collector. Three crates at `2` cut the damage the object takes to an eighth, rounded down and never below 1.
