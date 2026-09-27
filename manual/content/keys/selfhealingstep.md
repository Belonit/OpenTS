---
key: SelfHealingStep
summary: The strength one self-healing tick restores to this type.
see_also: ["SelfHealStep", "SelfHealingCap", "SelfHealingRate", "SelfHealing", "system:repair"]
when_omitted:
  kind: value
  value: "-1"
  note: Any value below zero takes the step from `SelfHealStep`.
---

```ini title="rules.ini"
[4TNK] ; a UnitType registered in [VehicleTypes]
SelfHealingStep=15
```

Each [self-healing](/systems/repair/#self-healing) tick restores this many strength points to an object of this type. It replaces the rules-wide [`SelfHealStep`](/keys/selfhealstep/) for this type. It has no effect unless the object heals itself, through [`SelfHealing=yes`](/keys/selfhealing/) or the `SELF_HEAL` ability.

This key is the only way to give one type a different step. The rules-wide step applies to every type alike: unlike [`RepairStep`](/keys/repairstep/) and [`IRepairStep`](/keys/irepairstep/), it does not even treat infantry differently.

`0` heals one point per tick. Healing never raises strength above the type's [`Strength`](/keys/strength/#scope-aircrafttype).
