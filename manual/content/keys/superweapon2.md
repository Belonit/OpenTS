---
key: SuperWeapon2
summary: A second superweapon a standing structure of this type grants its owner.
see_also: [SuperWeapon, "system:superweapons"]
when_omitted:
  kind: value
  value: none
---

`SuperWeapon2=` works exactly like [`SuperWeapon=`](/keys/superweapon/), independently and at the same time. Granting and removing the weapon, the [`AuxBuilding=`](/keys/auxbuilding/) test, plugs and the missile-silo match all read both keys. A structure can therefore grant two superweapons, as the stock Nod missile silo does with the multi missile and the chem missile. There is no third key.

```ini title="rules.ini"
[NAMISL]        ; Missile Silo
SuperWeapon=MultiSpecial
SuperWeapon2=ChemicalSpecial
NukeSilo=yes
```
