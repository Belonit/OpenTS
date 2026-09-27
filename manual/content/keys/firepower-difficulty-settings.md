---
key: FirePower
summary: The multiplier a difficulty setting applies to the damage its houses deal by firing a weapon.
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1"
  note: A later file that contains the section without this key resets it to 1.
---

`FirePower` multiplies the damage of the weapons fired by houses in this difficulty slot. A value above 1 deals more damage. `[Easy]`, `[Normal]` and `[Difficult]` each set a value, and a house uses the one for [its difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot).

```ini title="rules.ini"
[Difficult]
FirePower=1.2
```

The multiplier scales the [`Damage`](/keys/damage/#scope-weapontype) of each projectile an object fires from its weapon. A firepower crate and the veteran firepower bonus ([`VeteranCombat`](/keys/veterancombat/)) scale the same damage further.

These deal their damage without the multiplier:

- a nuclear missile launch;
- an EM pulse, from a structure or from a vehicle;
- other superweapon launches;
- projectiles created by a trigger action;
- the projectiles a splitting projectile releases;
- sonic weapons and weapons that use fire particles;
- weapons with a `Damage` of 0 or below, such as healing weapons.

A house's multiplier is computed each time the house is [assigned its slot](/systems/difficulty/#when-a-house-is-re-handicapped), so a later change to the section reaches the house only then. Outside a campaign game, it is also multiplied by the country's [`Firepower=`](/keys/firepower-housetype/); a campaign game ignores the country value.
