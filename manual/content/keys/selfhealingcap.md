---
key: SelfHealingCap
summary: The share of maximum strength at which this type stops healing itself.
see_also: ["SelfHealCap", "SelfHealingStep", "SelfHealingRate", "SelfHealing", "ConditionYellow", "system:repair"]
when_omitted:
  kind: value
  value: "-1"
  note: Any value below zero takes the ceiling from `SelfHealCap`.
---

```ini title="rules.ini"
[4TNK] ; a UnitType registered in [VehicleTypes]
SelfHealingCap=100%
```

`SelfHealingCap` sets how far objects of this type can [heal themselves](/systems/repair/#self-healing), as a share of maximum strength. It replaces the rules-wide [`SelfHealCap`](/keys/selfhealcap/) for this type. A higher value lets the object heal further.

A tick heals only while the object's strength is at or below this share, so healing stops up to one step past it. `100%` heals the object to maximum strength. A percentage and a plain fraction are read the same way, so `100%` equals `1`.

[`ConditionYellow`](/keys/conditionyellow/) still decides when the object counts as damaged and when its damage smoke stops, whatever this key is set to.
