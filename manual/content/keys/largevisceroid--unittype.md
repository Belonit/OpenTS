---
key: LargeVisceroid
scope: unittype
label: Large visceroid behavior
see_also: ["SmallVisceroid", "AltImage", "NonVehicle"]
when_omitted:
  kind: value
  value: "no"
---

The flag gives the vehicle the creature behavior that [`SmallVisceroid=yes`](/keys/smallvisceroid/#scope-unittype) describes, except merging. It wanders aimlessly, heads for Tiberium below [`ConditionYellow`](/keys/conditionyellow/) health, and draws its attack frames from [`AltImage`](/keys/altimage/).

It also has the same exemptions as a small visceroid:

- [`NonVehicle`](/keys/nonvehicle/) is forced on, whatever its section says;
- an EM pulse does not stun it;
- being immobilized does not stop it firing;
- it does not have to bring a turret to bear before it shoots;
- a [`Jellyfish=yes`](/keys/jellyfish/) unit never stings it;
- it is drawn without a shadow.

A large visceroid never merges. It neither calls a neighbor over nor is called over by one, and two of them beside each other block each other's cells like any other pair of vehicles.

This flag is separate from the type a merge produces, which [`LargeVisceroid`](/keys/largevisceroid/#scope-global-rules) in the global rules names. A type with this flag behaves as a large visceroid wherever it is placed, whether or not a merge can produce it.
