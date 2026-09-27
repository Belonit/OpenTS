---
key: Crushable
scope: aircrafttype
label: Crushable by vehicles
see_also: ["system:walls-and-gates", "CrushSound", "Crusher"]
when_omitted:
  kind: context-dependent
  note: An InfantryType section starts at yes. Every other object type in this scope starts at no.
---

`Crushable=yes` lets a crusher drive over the object or overlay. A crusher is a [`Crusher=yes`](/keys/crusher/) UnitType, or a vehicle whose type lists the `CRUSHER` ability on [`VeteranAbilities=`](/keys/veteranabilities/) or [`EliteAbilities=`](/keys/eliteabilities/) and that has reached the matching rank.

**An object** marked crushable is destroyed when a crusher enters its cell. The crusher plays the object's [`CrushSound`](/keys/crushsound/#scope-aircrafttype) and is credited with the kill. A crusher that is not a train leaves allied objects alone, and a train crusher crushes them too. An infantryman on its way to steal a crusher that is not a train is not crushed: the crusher is captured instead.

The lead car of a [train](/keys/istrain/), crusher or not, damages every object in a cell it enters except the crushable ones.

A crusher also plans around crushable objects:

- Its pathfinding does not treat a cell holding a crushable enemy object as blocked.
- A computer-controlled crusher drives at a crushable target inside the [`[CombatDamage] Crush=`](/keys/crush/) distance instead of firing on it. A crusher belonging to a human player never does this on its own, whatever [`AutoCrush=`](/keys/autocrush/#scope-aircrafttype) and [`PlayerAutoCrush=`](/keys/playerautocrush/) say.
- A crusher that has no weapon shows the move cursor over a crushable object, where an armed one would show the attack cursor.

**A wall overlay** marked crushable is destroyed outright when a crusher drives onto it, whatever its owner or damage stage. The crusher plays the overlay's `CrushSound` and rocks forward.

A crusher's pathfinding treats an enemy or unowned crushable wall as open ground. A crushable wall owned by an ally stays an obstacle, which the pathfinding routes around where it can.

**Any other overlay** marked crushable survives. A crusher driving onto it still plays the sound and rocks forward.

Route planning treats a cell that holds any crushable overlay, wall or not, as closed to a type whose [`MovementZone=`](/keys/movementzone/) is `Normal`, `Amphibious` or `Infantry`. Such a type plans its routes around the cell.

Any vehicle that moves with the drive locomotor, crusher or not, drives straight through a cell holding a crushable overlay. It does not curve into or out of that cell.
