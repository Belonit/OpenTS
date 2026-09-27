---
key: SelfHealRate
summary: The interval between self-healing ticks.
see_also: ["SelfHealingRate", "SelfHealStep", "SelfHealCap", "SelfHealing", "RepairRate", "system:repair"]
when_omitted:
  kind: value
  value: "-1"
  note: Any value below zero leaves self-healing on `RepairRate`, where it was before this key existed.
---

```ini title="rules.ini"
[General]
SelfHealRate=.05 ; example value, one tick every 45 frames
```

`SelfHealRate` sets the time between [self-healing](/systems/repair/#self-healing) ticks. A smaller value heals faster. A type that sets [`SelfHealingRate`](/keys/selfhealingrate/) uses that value instead.

The value is in minutes: it is multiplied by 900 frames and truncated to whole frames. At its default, [`RepairRate`](/keys/repairrate/) gives 14 frames.

An interval that truncates to zero frames is raised to one, whichever key supplied it. A value below `1/900` therefore heals on every frame. `RepairRate` has no such floor for structure repair, where a value that small [crashes the game](/keys/repairrate/).
