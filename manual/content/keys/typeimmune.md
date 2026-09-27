---
key: TypeImmune
summary: Stops an object taking damage from any object of exactly its own type and house, including itself.
see_also: [Immune, Armor, VeteranArmor]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MYARTILLERY] ; a UnitType registered in [VehicleTypes]
TypeImmune=yes ; the battery's splash cannot hurt its own members
```

A hit is blocked only when the attacker is of the same type and belongs to the same house. Fire from an allied house still lands, and so does fire from a different type, however similar.

A blocked hit costs the object no strength.

These hits still land in full:

- forced damage, such as a demolition charge going off, a vehicle crushing the object, a trigger destroying it, or a firestorm wall;
- damage with no attacker, such as a shot still in flight after the object that fired it has been destroyed;
- a [`Webby=yes`](/keys/webby/) warhead, which still entangles infantry.

Healing is never blocked.
