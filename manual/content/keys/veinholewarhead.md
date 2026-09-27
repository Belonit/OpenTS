---
key: VeinholeWarhead
summary: WarheadType vein damage is applied with.
see_also: ["system:veins", "VeinDamage", "Veinhole"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[CombatDamage]
VeinholeWarhead=VeinholeWH

[VeinholeWH] ; the WarheadType vein damage is applied with
Veinhole=yes
```

Vein attacks deal [`VeinDamage`](/keys/veindamage/) with this warhead, so its modifiers decide how much each armor type takes. If the warhead sets [`Veinhole=yes`](/keys/veinhole/), an object hurt by veins can fight back against the monster that owns them. [Standing in veins](/systems/veins/#standing-in-veins) gives the conditions.

:::caution[Set a vein warhead]
If `VeinholeWarhead` is not set, vein attacks still play over every vulnerable object in a field but deal no damage.
:::
