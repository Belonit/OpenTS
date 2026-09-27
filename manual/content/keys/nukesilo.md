---
key: NukeSilo
summary: Whether the structure can serve as the launch site of a MultiMissile or ChemMissile superweapon.
see_also: [SuperWeapon, WeaponType, "system:superweapons"]
when_omitted:
  kind: value
  value: "no"
---

A `NukeSilo=yes` structure is the launch site for a repeating `Type=MultiMissile` or `Type=ChemMissile` superweapon that its type names. When such a weapon is fired, the game takes the first declared BuildingType that has this flag and names the weapon in [`SuperWeapon=`](/keys/superweapon/) or [`SuperWeapon2=`](/keys/superweapon2/). One of the firing house's structures of that type launches the missile.

```ini title="rules.ini"
[NAMISL]        ; Missile Silo
SuperWeapon=MultiSpecial
SuperWeapon2=ChemicalSpecial
NukeSilo=yes
```

Only that first type is searched. A later silo type that grants the same weapon never launches it, even when the house owns no structure of the first type.

The silo opens its door, holds it open while the missile leaves, then closes it and returns to guard. [Multi missile and chem missile](/systems/superweapons/#multi-missile-and-chem-missile) covers the missile itself, which does not always come from the fired weapon's own `WeaponType=`.

:::caution[Without a silo the shot is spent for nothing]
A repeating missile weapon can launch only from a silo. If no `NukeSilo=yes` type grants the weapon, or the house has no structure of that type on the map when it fires, the weapon still discharges. Its charge is used up and no missile is launched. Its countdown then restarts as after any shot, or stays stopped for a [`ManualControl=yes`](/keys/manualcontrol/) weapon. A one-time missile, whose superweapon is removed once it fires, needs no silo; it enters from the map edge nearest the target.
:::
