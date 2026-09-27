---
key: Storage
summary: Units of Tiberium an object can hold.
see_also: ["system:tiberium", "Harvester", "SiloDamage", "Value"]
when_omitted:
  kind: value
  value: "0"
---

A harvester holds up to this many units of Tiberium. It takes one unit for each growth stage it lifts from a cell, and heads home to unload once it is full. A harvester type with `Storage=0` cannot harvest. The stock harvester sets `Storage=28`; at the stock `Value` of 25 for green Tiberium, a full load of it is worth 700 credits. A [weeder](/systems/veins/) also fills to this value. It takes two units for each vein cell it lifts, or one when the first unit fills it.

A structure adds this value to its house's storage capacity while it stands. Harvested Tiberium fills the house's storage structures one at a time, and whatever does not fit is lost. A computer-controlled house in a skirmish or multiplayer game converts Tiberium to credits at once and needs no storage. [Credits and storage](/systems/tiberium/#credits-and-storage) covers what happens to stored Tiberium when a structure is captured, destroyed or sold.

Stored Tiberium is counted in units, not credits. Each unit keeps the Tiberium type it came from and is priced at that type's [`Value`](/keys/value/) when the house spends it.

Any vehicle or structure type with a nonzero `Storage` also counts as a Tiberium target. Team missions whose quarry is harvesters and [`Thief=yes`](/keys/thief/) infantry pick their targets only from these objects. A hunting aircraft outside campaigns looks for them first. [Target selection](/systems/target-selection/) covers the scans.
