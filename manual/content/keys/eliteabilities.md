---
key: EliteAbilities
summary: The abilities an object of this type gains at elite rank, on top of its veteran abilities.
see_also: ["system:veterancy"]
when_omitted:
  kind: value
  value: ""
---

An elite object has every ability in this list as well as every ability in its type's [`VeteranAbilities`](/keys/veteranabilities/). A veteran of the same type gets nothing from this list.

The value is a comma-separated list of ability tokens, matched without regard to letter case and parsed exactly like `VeteranAbilities`, including the whitespace rule described there. [The ability table](/systems/veterancy/#abilities) lists the accepted tokens and what each one does.

```ini title="rules.ini"
[MYTANK] ; example UnitType
VeteranAbilities=FIREPOWER
EliteAbilities=ROF,SELF_HEAL
```

An elite `MYTANK` deals more damage, reloads faster and repairs itself; a veteran one only deals more damage.
