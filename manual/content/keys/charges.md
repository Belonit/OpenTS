---
key: Charges
summary: Makes a structure wind its turret animation up to full charge before the weapon will fire.
see_also: ["TurretAnim", "TurretChargeAnimRate", "TurretAnimIsExclusive", "IsLaser"]
when_omitted:
  kind: value
  value: "no"
---

A structure with a `Charges=yes` weapon in its first weapon slot must charge its turret before it can fire. Each wind-up adds its time to the weapon's reload delay.

```ini title="rules.ini"
[MyChargeLaser] ; example WeaponType
Charges=yes
IsLaser=yes
ROF=120
```

The flag works only on structures and only in the first weapon slot. A vehicle, infantry or aircraft with the weapon fires at once and pays only its ordinary reload.

## Starting and losing the charge

The structure starts charging when all of these hold:

- it has a target, and one of its weapons could fire at that target once the turret faced it;
- its reload delay has run out;
- its house has full power, and the structure is switched on;
- it is not still being built.

The weapon test in the first condition includes range, whether the weapon can hit an air or ground target, [ion storms](/keys/ionsensitive/), and cloaking of the structure or its target. It ignores ammunition, so a structure with no rounds left still charges.

Charging plays the structure's [`TurretAnim`](/keys/turretanim/) and the [`TeslaCharge`](/keys/teslacharge/) sound. [`TurretChargeAnimRate`](/keys/turretchargeanimrate/) sets how long the wind-up takes.

If the structure loses its target, its house drops below full power, or the structure is switched off, the turret discharges. It charges again from the start once the conditions return.

:::danger[Give the structure a turret animation]
A charging structure needs a `TurretAnim` that names a registered AnimType, and a `TurretAnimDamaged` that does too if it can charge while damaged. Otherwise the game crashes when the structure starts charging. [`TurretAnim`](/keys/turretanim/) gives the details.
:::

## When a shot spends the charge

Only an [`IsLaser=yes`](/keys/islaser/) weapon spends the charge, and only when the structure fires its last round. A structure with the default unlimited [`Ammo`](/keys/ammo/) counts every shot as its last, so it recharges before each shot. A structure with a stock of rounds keeps its charge until it fires the last one.

A charging weapon that is not a laser never spends its charge by firing. The structure winds up once, then fires at its ordinary reload rate for as long as it keeps its target.
