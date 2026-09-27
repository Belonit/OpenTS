---
key: TurretChargeAnimRate
summary: How many game frames each step of a building's weapon charge takes.
see_also: ["TurretAnim", "TurretAnimIsExclusive", "Charges", "ChargeAnim"]
when_omitted:
  kind: value
  value: "3"
---

`TurretChargeAnimRate` sets how long a building with a [`Charges=yes`](/keys/charges/) primary weapon takes to charge before it can fire. A higher value makes the wind-up slower.

The charge counts from the [`Start`](/keys/start/) frame of the building's [`TurretAnim`](/keys/turretanim/) animation up to that animation's [`LoopEnd`](/keys/loopend/) frame. It advances one frame every `TurretChargeAnimRate` game frames, and the weapon can fire once the count reaches `LoopEnd`. The wind-up therefore takes about `(LoopEnd - Start) * TurretChargeAnimRate` game frames. If the turret animation has ended before the count gets there, the charge completes at frame 12 instead.

A building at or below [`ConditionYellow`](/keys/conditionyellow/) health starts its charge with [`TurretAnimDamaged`](/keys/turretanimdamaged/), so that animation's `Start` and `LoopEnd` set the count.

```ini title="rules.ini"
[MYOBELISK] ; a BuildingType registered in [BuildingTypes]
Primary=MyChargeLaser  ; a WeaponType with Charges=yes
TurretAnim=MYOBEL_C    ; an AnimType registered in [Animations]
TurretChargeAnimRate=1 ; the count advances every game frame
```

A [`ChargeAnim=yes`](/keys/chargeanim/) building shows the turret animation frame the count has reached, so the rate also sets how fast that animation appears to play. [`Charges`](/keys/charges/) covers when charging starts, what empties the charge, and when a shot spends it.

:::caution[Set a value of 1 or more]
At `0` the count never advances, so the building never finishes charging and never fires.
:::
