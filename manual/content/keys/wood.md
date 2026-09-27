---
key: Wood
summary: Lets the warhead damage terrain objects, and wall overlays whose armor is wood.
see_also: ["system:walls-and-gates", "Wall", "Armor"]
when_omitted:
  kind: value
  value: "no"
---

Only a `Wood=yes` warhead can damage a terrain object such as a tree, and even that warhead cannot damage a terrain type that is [`Immune=yes`](/keys/immune/#scope-aircrafttype).

The flag also decides whether a vehicle can clear a terrain object that blocks its path. The vehicle treats the terrain object as something to destroy when the weapon it would use against it has a `Wood=yes` warhead and the terrain type is not `Immune=yes`. Otherwise the terrain object is impassable to it, unless the vehicle is a crusher and the terrain type is [`Crushable=yes`](/keys/crushable/).

A `Wood=yes` warhead also damages a wall overlay whose [`Armor`](/keys/armor/#scope-aircrafttype) is `wood`, in the same way a [`Wall=yes`](/keys/wall/#scope-warheadtype) warhead damages any wall overlay. [Taking damage](/systems/walls-and-gates/#taking-damage) covers what each hit does to the wall.

Two checks also accept a `Wood=yes` warhead against a wood-armored wall:

- A vehicle's blocked-path test, which uses its primary weapon's warhead.
- The player's attack cursor over a wall owned by a house that is not an ally, which uses the warhead of the object's primary weapon.

Two other checks accept only `Wall=yes`, so a warhead with `Wood=yes` alone gains nothing from them:

- The [computer's automatic wall scan](/systems/target-selection/#what-each-kind-of-object-considers). A computer-controlled object whose primary weapon's warhead is not `Wall=yes` never picks a wall as a target by itself, even a wood wall.
- Infantry's blocked-path test. Infantry whose primary weapon's warhead is not `Wall=yes` treat any wall as impassable, including a wood wall.

[Walls in combat and movement](/systems/walls-and-gates/#walls-in-combat-and-movement) covers what each kind of object does at a wall.
