---
key: AA
summary: Allows the projectile to be fired at targets that are in the air.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

A weapon whose projectile is not anti-aircraft cannot fire at anything in the air. The test is on the target's height, not its kind: an object is in the air once it is placed on the map and at least one terrain level above the ground beneath it. An aircraft in flight, a [`JumpJet=yes`](/keys/jumpjet/) infantry in flight and a vehicle lifted by a flying locomotor are all refused. A hover vehicle never counts as airborne.

The same projectile also limits how steeply the weapon can fire upward. When the firer is not itself airborne and the projectile is not [`Arcing=yes`](/keys/arcing/), a target is out of range if it is at least as high above the firer as it is away horizontally. `AA=yes` removes that limit.

An object does not return fire at an aircraft that damaged it unless the weapon it would use against that aircraft has an `AA=yes` projectile. This holds even when the aircraft has landed. [Retaliation](/systems/target-selection/#retaliation) lists the other conditions.

An `AA=yes` projectile detonates as soon as it comes within half a cell of its target when that target is an aircraft, landed or not, or a `JumpJet=yes` infantry in flight.

With [`AG=no`](/keys/ag/) beside it, the weapon is air-only: it fires at no object on the ground. `AG` says when such a weapon can still be ordered to fire at a map cell. The default pairing, `AA=no` with `AG=yes`, is the ground-only mirror.

Automatic target scans also read this setting. A weapon slot whose projectile is `AA=yes` adds aircraft to the kinds of target the object looks for, unless [`AV=yes`](/keys/av/) on the same projectile limits the slot to vehicles. [What each kind of object considers](/systems/target-selection/#what-each-kind-of-object-considers) says when an object's weapons fill that list. `AV` has no effect on the firing test.
