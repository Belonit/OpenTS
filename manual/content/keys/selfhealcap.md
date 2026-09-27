---
key: SelfHealCap
summary: The share of maximum strength at which self-healing stops.
see_also: ["SelfHealingCap", "SelfHealStep", "SelfHealRate", "SelfHealing", "ConditionYellow", "system:repair"]
when_omitted:
  kind: value
  value: "-1"
  note: Any value below zero leaves the ceiling on `ConditionYellow`, where it was before this key existed.
---

```ini title="rules.ini"
[General]
SelfHealCap=75% ; example value
```

`SelfHealCap` sets how far an object can [heal itself](/systems/repair/#self-healing), as a share of its maximum strength. A higher value lets it heal further. A type that sets [`SelfHealingCap`](/keys/selfhealingcap/) uses that value instead.

A tick heals only while the object's strength is at or below this share, so healing stops one step past it. `100%` heals an object to maximum strength, and no value heals past it. A percentage and a plain fraction are read the same way, so `75%` equals `.75`.

[`ConditionYellow`](/keys/conditionyellow/) still decides when an object counts as damaged. A ceiling below it leaves a healed object in its damaged state, and a structure keeps its damage smoke. A ceiling above it heals the object out of that state partway up. [Self-healing](/systems/repair/#self-healing) describes what else stays damaged.
