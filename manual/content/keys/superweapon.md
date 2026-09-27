---
key: SuperWeapon
summary: The superweapon a standing structure of this type grants its owner.
see_also: [SuperWeapon2, AuxBuilding, "system:superweapons"]
when_omitted:
  kind: value
  value: none
---

A house [holds the named superweapon](/systems/superweapons/#from-a-structure-or-a-plug) while it owns at least one structure of this type standing on the map, and loses it when the last one is gone, unless a trigger has [granted it outright](/systems/superweapons/#granted-outright). Switching the structure off, or a power shortfall, can suspend the weapon without removing it; [Power output and drain](/systems/power/#superweapons) covers when.

The value names a section listed in `[SuperWeaponTypes]`. A name that matches no listed section grants nothing. The key holds one superweapon; [`SuperWeapon2=`](/keys/superweapon2/) grants a second.

The key also works on a plug: a structure fitted with this type as a plug grants the plug's superweapon too. A plug's grant skips the [`AuxBuilding=`](/keys/auxbuilding/) test that a structure's own grant must pass.

```ini title="rules.ini"
[GAPLUG3]       ; Ion Cannon Uplink, a plug for the GDI Upgrade Center
PowersUpBuilding=GAPLUG
SuperWeapon=IonCannonSpecial
```

A repeating missile superweapon needs a launch site; [`NukeSilo`](/keys/nukesilo/) covers which structure launches it.
