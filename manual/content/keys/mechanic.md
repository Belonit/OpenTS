---
key: Mechanic
summary: Turns a healing weapon away from infantry and onto vehicles.
see_also: ["OmniHealer", "Damage", "AmbientDamage", "Passengers", "Verses", "system:repair", "system:target-selection", "system:warheads"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MECHANIC] ; an InfantryType registered in [InfantryTypes]
Mechanic=yes
```

The key changes which patients a healer takes; it does not make an object a healer. An object is a healer when the [`Damage`](/keys/damage/#scope-weapontype) plus [`AmbientDamage`](/keys/ambientdamage/) of its primary and secondary weapons averages below zero. On any other object the key does nothing.

A healer takes these patients:

- An infantry healer without the key takes infantry.
- An infantry healer with the key takes vehicles and no longer takes infantry.
- A vehicle healer takes vehicles, with or without the key.
- A healer with [`OmniHealer=yes`](/keys/omnihealer/) takes infantry and vehicles alike.

A vehicle, for this purpose, is a driven vehicle other than a [`NonVehicle=yes`](/keys/nonvehicle/) type, an aircraft on the ground, or a structure with [`UndeploysInto`](/keys/undeploysinto/) set other than a construction yard. An ordinary structure, an airborne aircraft, and any object not allied to the healer are never patients.

The key applies to both the cursor and the [automatic scan](/systems/target-selection/). A mechanic offers the repair cursor over a damaged allied vehicle, walks to one it finds while guarding, and keeps repairing it until it is undamaged. Holding force-move over an allied transport withdraws the repair offer, so the player can still order the mechanic aboard a damaged transport.

Only infantry use the key. It does not change [what a healing shot does on arrival](/systems/warheads/#healing).
