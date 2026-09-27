---
key: IgnoresFirestorm
scope: aircrafttype
label: Object types
see_also: ["system:laser-fences"]
when_omitted:
  kind: value
  value: "no"
---

`IgnoresFirestorm=yes` lets objects of this type pass a raised firestorm wall unharmed. The wall tests only vehicles, infantry, aircraft and projectiles, so the flag has no effect on any other type. The wall skips flagged objects in four checks:

- when it destroys the vehicles, aircraft and infantry standing in a raised section's cell;
- when it destroys vehicles and infantry moving into that cell from nearby;
- when an object on the flying locomotor moves over a raised section's cell;
- when a projectile enters a raised section's cell.

[What a raised section destroys](/systems/laser-fences/#what-a-raised-section-destroys) describes what the wall does to everything it does not skip.

An [`Inviso=yes`](/keys/inviso/) projectile is checked along its line of fire instead of cell by cell. That check ignores the flag and destroys the projectile at the first raised section on the line.

The flag does not open the wall to ground movement. A raised section's cell stays closed to vehicles, so an exempt vehicle still cannot drive through it.

:::caution[A jumpjet is destroyed anyway]
A type whose [`Locomotor=`](/keys/locomotor/) is the jumpjet locomotor is still destroyed when it moves over a raised section's cell, even with `IgnoresFirestorm=yes`. The jumpjet's check does not read this flag.
:::
