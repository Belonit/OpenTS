---
key: Armor
scope: aircrafttype
label: Armor class
see_also: [Verses, Wood, Immune]
when_omitted:
  kind: context-dependent
  note: Most object types start at none. A TerrainType starts at wood.
---

A warhead's damage to an object of this type is multiplied by the warhead's [`Verses`](/keys/verses/) entry for the object's [armor class](/reference/enums/armor/). Forced damage, such as a C4 charge destroying a structure, skips this multiply. A vehicle, infantryman, aircraft or structure also weighs each of its weapons against the target's class when it picks which weapon to fire.

Other reductions come before and after the `Verses` multiply. A prone infantryman's reduction, the house and crate armor divisors, and the veteran armor bonus apply before it. Distance falloff and the [`MinDamage`](/keys/mindamage/) and [`MaxDamage`](/keys/maxdamage/) limits apply after it. [What the target loses](/systems/warheads/#what-the-target-loses) lists every step in order.

An OverlayType's class matters only for a wall. Overlays never take damage through a `Verses` list. A wall overlay whose class is `wood` can also be reduced by a [`Wood=yes`](/keys/wood/) warhead, in addition to the wall-destroying warheads that reduce any wall.

A TerrainType's class is used both ways: as a `Verses` entry when the terrain object takes damage, and as a `wood` test by [the rules that set it on fire](/keys/treefire/).

[`Tiberium=yes`](/keys/tiberium/#scope-overlaytype) sets an overlay's class to `wood` after its section is read, so an `Armor=` in such a section has no effect.
