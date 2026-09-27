---
key: ToProtect
summary: Whether damage to the object makes its computer house call defenders back to it.
see_also: ["system:base-attacked", ComputerBaseDefenseResponse]
when_omitted:
  kind: value
  value: "no"
---

When an object of this type is damaged, its house calls defenders back as it would for a damaged structure. This [base defense response](/systems/base-attacked/#calling-defenders-back) is sized from the attacker's [`ThreatPosed`](/keys/threatposed/) and answered by the house's infantry and vehicles. The flag works only for a computer house; a human player's protected objects call no one. [When the call-up is refused](/systems/base-attacked/#when-the-call-up-is-refused) lists the other cases that stop it.

```ini title="rules.ini"
[MYHARV] ; example UnitType
ToProtect=yes
```

:::caution[Only hits that leave the object's condition unchanged call for help]
A protected infantry, vehicle or aircraft calls for help only on a hit that damages it without changing its condition. It calls no one on the hit that takes it below half strength, on the hit that takes it below [`ConditionRed`](/keys/conditionred/), or on the hit that destroys it. A protected structure still calls for help on those hits through [the structure rule](/systems/base-attacked/#damage-to-a-structure).
:::
