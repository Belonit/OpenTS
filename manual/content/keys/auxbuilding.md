---
key: AuxBuilding
summary: A BuildingType the house must own before a structure may grant this superweapon.
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: none
---

A structure grants this weapon [through its own `SuperWeapon=` or `SuperWeapon2=`](/systems/superweapons/#from-a-structure-or-a-plug) only while its house owns at least one standing structure of the named BuildingType. Losing the last one removes a weapon that structures granted, together with any charge it had built, unless a plug still grants it. A later grant starts the charge from the beginning. A one-time copy and a weapon from the [Add repeating special weapon](/mapping/actions/taction-full-special/) trigger action are kept.

`none` removes the requirement. A misspelled name is not rejected; it withholds the weapon for good, because no structure of that type is ever built.

The stock chem missile requires the Nod waste facility:

```ini title="rules.ini"
[ChemicalSpecial]
Type=ChemMissile
AuxBuilding=NAWAST   ; Nod Waste Facility
```

:::caution[A plug ignores this value]
A plug fitted to a structure grants its [`SuperWeapon=`](/keys/superweapon/) and [`SuperWeapon2=`](/keys/superweapon2/) weapons without this check. In the stock rules the ion cannon and the drop pods come only from plugs, so `AuxBuilding=` has no effect on them. The hunter seeker comes both from a plug and from the Nod temple, and only the temple's grant is checked.
:::
