---
key: Wall
scope: warheadtype
label: Wall destroyer
see_also: ["system:walls-and-gates", "Wood"]
when_omitted:
  kind: value
  value: "no"
---

An explosion from a `Wall=yes` warhead can damage the wall overlay in the cell it lands in. The chance of a hit landing depends on the explosion's raw damage, and [`Verses`](/keys/verses/) does not apply to walls; [Taking damage](/systems/walls-and-gates/#taking-damage) gives the rule. A warhead without the flag leaves walls undamaged, unless it is [`Wood=yes`](/keys/wood/) and the wall's armor is wood.

In scenarios with [`DestroyableBridges=yes`](/keys/destroyablebridges/), the same explosions can damage bridges. Whatever that setting, they crack ice in the explosion's cell unless they go off up on a bridge.

The flag also affects how objects treat walls:

- A vehicle that cannot crush a wall in its path treats it as destroyable instead of impassable when its primary weapon's warhead sets this flag, or is `Wood=yes` and the wall's armor is wood.
- Infantry treat a wall as destroyable only when the primary weapon's warhead sets this flag. `Wood=yes` does not count for them.
- A player-controlled object shows the attack cursor over an enemy wall when the warhead in its first weapon slot sets this flag, or is `Wood=yes` and the wall's armor is wood.
- The [computer's automatic search for walls to shoot](/systems/target-selection/#what-each-kind-of-object-considers) skips any object whose primary weapon's warhead lacks the flag. The difficulty's [`DestroyWalls`](/keys/destroywalls/) setting can turn that search off.

[Walls in combat and movement](/systems/walls-and-gates/#walls-in-combat-and-movement) explains what a vehicle or infantryman does at a wall it reads as destroyable.
