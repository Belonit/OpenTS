---
key: SelfHealingRate
summary: The interval between this type's self-healing ticks.
see_also: ["SelfHealRate", "SelfHealingStep", "SelfHealingCap", "SelfHealing", "system:repair"]
when_omitted:
  kind: value
  value: "-1"
  note: Any value below zero takes the interval from `SelfHealRate`.
---

```ini title="rules.ini"
[4TNK] ; a UnitType registered in [VehicleTypes]
SelfHealingRate=.004 ; example value, one tick every 3 frames
```

`SelfHealingRate` sets the time between [self-healing](/systems/repair/#self-healing) ticks for this type. It replaces the rules-wide [`SelfHealRate`](/keys/selfhealrate/) for this type. A smaller value heals faster.

The value is in minutes: it is multiplied by 900 frames and truncated to whole frames. An interval that truncates to zero frames is raised to one, so the object heals on every frame.

Ticks fall on game frames whose number is a multiple of the interval. Every object on the same interval therefore heals on the same frames.
