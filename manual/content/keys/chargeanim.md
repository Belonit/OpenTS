---
key: ChargeAnim
summary: Drives a structure's turret animation from its charge counter.
see_also: ["TurretAnim", "TurretChargeAnimRate", "TurretAnimIsExclusive", "Charges"]
when_omitted:
  kind: value
  value: "no"
---

`ChargeAnim=yes` makes the animation named by [`TurretAnim=`](/keys/turretanim/) show a structure's charge-up. On a structure without a turret, the flag adds two things: the animation is created when the structure opens, and its frame follows a charge counter that advances only while the structure charges. Without the flag, a charging structure still shows `TurretAnim` from the start of each charge, but the animation plays at its own rate.

On a turret-equipped type the flag has the same effect on the frame: the charge counter replaces the turret's facing as its source.

The flag does not make the structure charge. A [`Charges=yes`](/keys/charges/) primary weapon does that, and [`TurretChargeAnimRate`](/keys/turretchargeanimrate/) sets how fast the charge runs.

```ini title="art.ini"
[MYOBEL] ; example obelisk, drawn from its own Image ID
ChargeAnim=yes
```

```ini title="rules.ini"
[MYOBEL]
TurretAnim=MYOBEL_A ; the animation the charge counter drives
Primary=MyLaser     ; a Charges=yes WeaponType
```

With [`TurretAnimIsExclusive=yes`](/keys/turretanimisexclusive/), the animation is not created when the structure opens, and appears only once the structure begins charging.

With [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/), nothing is created when the structure opens either. Avoid giving such a structure a `Charges=yes` weapon: when it begins charging, the game crashes unless an animation has the same name as the voxel turret.

The flag also stops the structure's own artwork from looping. Outside construction and deconstruction, its sequences, the idle sequence included, run past their last frame instead of starting over. On an unarmed structure a queued mission can therefore be held up, because the end of a sequence no longer lets it start. A structure with a weapon is unaffected, since it is ready for a new mission on every pass it spends on guard.
