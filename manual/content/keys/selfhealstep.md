---
key: SelfHealStep
summary: The strength one self-healing tick restores.
see_also: ["SelfHealingStep", "SelfHealCap", "SelfHealRate", "SelfHealing", "RepairStep", "IRepairStep", "system:repair"]
when_omitted:
  kind: value
  value: "1"
---

```ini title="rules.ini"
[General]
SelfHealStep=1
```

Each self-healing tick restores this many strength points to an object that [mends itself](/systems/repair/#self-healing). It applies to structures, vehicles, aircraft and infantry alike. A type with [`SelfHealingStep`](/keys/selfhealingstep/) at `0` or above uses that value instead.

A step below `1` heals `1` point, so `0` and negative values still heal a point per tick. Healing never raises strength above the object's maximum.

[`RepairStep`](/keys/repairstep/) and [`IRepairStep`](/keys/irepairstep/) do not affect self-healing. They apply to the repair wrench, the service depot, the hospital and Tiberium healing.
