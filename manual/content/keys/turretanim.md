---
key: TurretAnim
summary: The animation a building's turret is drawn from, or the voxel model that replaces it.
see_also: ["TurretAnimDamaged", "TurretAnimIsVoxel", "BarrelAnimIsVoxel", "VoxelBarrelFile", "TurretAnimX", "Turret"]
when_omitted:
  kind: value
  value: ""
---

Unless [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) is set, the value is an AnimType ID. The animation is drawn at the offset [`TurretAnimX`](/keys/turretanimx/) and [`TurretAnimY`](/keys/turretanimy/) give.

A [`Turret=yes`](/keys/turret/) or [`ChargeAnim=yes`](/keys/chargeanim/) building starts the animation when its construction finishes. [`TurretAnimIsExclusive=yes`](/keys/turretanimisexclusive/) holds it back until the weapon charges. Every game frame, the building then picks the animation's frame:

- A `Turret=yes` building shows the frame for the direction its turret points, one of 32.
- A `ChargeAnim=yes` building shows the frame its charge has reached instead.

A building whose primary weapon is [`Charges=yes`](/keys/charges/) also starts the animation each time it begins to charge.

## Voxel turrets and barrels

With `TurretAnimIsVoxel=yes`, the value is a voxel base name and no animation is started. With [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) alone, the value stays an AnimType ID and the animation still runs; the building draws it in front of or behind its voxel barrel.

Under either flag, the engine loads models named after the value. Each model is a `.VXL` file with the `.HVA` file of the same name beside it.

1. The engine looks for `TUR` in the value, starting at the fifth character. A `TUR` in the first four characters does not count.
2. If it finds one, it loads `<name>.VXL` as the turret model. The barrel model's name is the value with that `TUR` and everything after it replaced by `BARL`, and [`VoxelBarrelFile`](/keys/voxelbarrelfile/) is not read.
3. If it finds none, it loads no turret model. A `BarrelAnimIsVoxel=yes` building takes its barrel model from `VoxelBarrelFile`. Otherwise the barrel model is `<name>.VXL`, which a `TurretAnimIsVoxel=yes` building draws as one piece that both turns and elevates.

```ini title="rules.ini"
[MYTOWER] ; a BuildingType registered in [BuildingTypes]
Turret=yes
TurretAnimIsVoxel=yes
TurretAnim=MYTWRTUR ; drawn from MYTWRTUR.VXL, its barrel from MYTWRBARL.VXL
```

## Wall towers

The building named by [`WallTower`](/keys/walltower/) starts with this animation like any other. Fitting a plug replaces it with a lettered animation: the tower's Image ID with `_B`, `_C` or `_D` appended. The letter follows the number of upgrade levels the tower's plugs have filled, which [`PowersUpToLevel`](/keys/powersuptolevel/) sets. One level gives `_B`, two give `_C` and three give `_D`.

When the tower's health falls to [`ConditionYellow`](/keys/conditionyellow/) or below, [`TurretAnimDamaged`](/keys/turretanimdamaged/) replaces the animation showing. When repairs lift it back above, `TurretAnim` replaces it. Each replacement happens only when that key names a registered AnimType; otherwise the lettered animation stays.

Once replaced, the lettered animation comes back only when another plug is fitted. Removing a `Turret=yes` plug leaves the tower with no turret animation until another plug is fitted.

:::danger[A charging weapon crashes without this animation]
Give a building whose primary weapon is [`Charges=yes`](/keys/charges/) a `TurretAnim` that names a registered AnimType. If the key is unset or names no registered AnimType, the game crashes when that building starts charging at its first target. A voxel base name under `TurretAnimIsVoxel=yes` counts as no AnimType. A damaged building charges with [`TurretAnimDamaged`](/keys/turretanimdamaged/) instead, so that name must resolve as well.
:::
