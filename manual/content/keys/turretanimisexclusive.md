---
key: TurretAnimIsExclusive
summary: Runs a building's turret animation only while its weapon is charging, in place of its second active animation.
see_also: ["TurretAnim", "ActiveAnimTwo", "TurretChargeAnimRate", "Charges"]
when_omitted:
  kind: value
  value: "no"
---

A building normally runs its turret animation and its [`ActiveAnimTwo`](/keys/activeanimtwo/) at the same time. With `TurretAnimIsExclusive=yes`, it never runs both:

- While its weapon is charging or holds a charge, the building shows its turret animation and stops `ActiveAnimTwo`.
- At every other time it shows `ActiveAnimTwo` and no turret animation. This includes a building that has just been built, is being repaired or has just lost its target.

`ActiveAnimTwo` starts again as soon as the charge is spent.

```ini title="rules.ini"
[MYOBELISK] ; a BuildingType registered in [BuildingTypes]
Primary=MyChargeLaser ; a WeaponType with Charges=yes
TurretAnim=MYOBEL_C   ; an AnimType registered in [Animations]
TurretAnimIsExclusive=yes
```

Only a building whose primary weapon is [`Charges=yes`](/keys/charges/) ever charges. On any other building, this flag hides the turret animation permanently.
