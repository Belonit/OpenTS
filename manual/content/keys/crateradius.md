---
key: CrateRadius
summary: The distance from an opened crate within which its sweeping results reach other objects, in cells.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: "2.5"
  note: Fractions are accepted; the default reaches 640 leptons at 256 leptons to the cell.
---

The cloak, veterancy, armor, firepower and speed crate results affect every object on the ground whose center is closer than this distance to the center of the crate's cell. Raising the value spreads each of these results over more objects. The heal result is not limited by this setting: it restores every object of the collector's house.

None of these results checks ownership. Allied, enemy and neutral objects inside the circle, structures included, are affected like the collector's own.

Each result still has its own filter inside the circle:

- veterancy promotes only objects whose type has [`Trainable=yes`](/keys/trainable/), as [Promotion without kills](/systems/veterancy/#promotion-without-kills) describes;
- armor skips an object that an earlier armor crate has already boosted, unless [`ArmorCrateStacks=yes`](/keys/armorcratestacks/);
- firepower skips an object that an earlier firepower crate has already boosted, unless [`FirepowerCrateStacks=yes`](/keys/firepowercratestacks/);
- speed always skips an object that an earlier speed crate has already boosted, and it also skips structures and aircraft.

[Results that sweep a radius](/systems/crates/#results-that-sweep-a-radius) covers what each result does to the objects it reaches.
