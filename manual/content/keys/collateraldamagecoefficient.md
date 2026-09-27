---
key: CollateralDamageCoefficient
summary: Multiplies a destroyed object's maximum strength to give the collateral figure that sizes its death explosion.
see_also: [Explodes, Strength, ExpSpread, Cyborg, Storage]
when_omitted:
  kind: context-dependent
  note: "`1` for an AircraftType, BuildingType or UnitType and `0.66` for an InfantryType. A `Cyborg=yes` InfantryType falls to `0.33`, but only in rules files read after the one that sets `Cyborg=yes`, because the cyborg flag is read after this default is chosen."
---

```ini title="rules.ini"
[MYAMMOTRUCK] ; a UnitType registered in [VehicleTypes]
Explodes=yes
Strength=200
CollateralDamageCoefficient=2.5 ; a collateral figure of 500
```

A destroyed object's collateral figure is this coefficient times its type's [`Strength`](/keys/strength/#scope-aircrafttype). `Strength` is the maximum, not the strength the object had left. A structure adds, for each Tiberium type in its [`Storage`](/keys/storage/), the amount held times that Tiberium's [`Power`](/keys/power/#scope-tiberium), so a full refinery blasts harder than an empty one.

The figure is used only when the object explodes on death: its type is `Explodes=yes`, or its rank grants the [explodes ability](/systems/veterancy/#abilities). The blast also needs a weapon in the object's first weapon slot, because it uses that weapon's warhead. [`Explodes`](/keys/explodes/#scope-aircrafttype) covers how the figure sets the blast's damage, radius and animation. Any figure below 100 gives the smallest radius.

:::caution[Repeat the key in every rules file that names the section]
Each rules file that contains the type's section resets the coefficient to the default for its kind before reading this key, even when the file sets only other keys. Write `CollateralDamageCoefficient` in every file that contains the section.
:::
