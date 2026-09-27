---
key: Upgrades
summary: How many upgrade plugs the structure accepts.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: "0"
---

`Upgrades` is the number of upgrade plugs a structure of this type can hold. A plug is a BuildingType with [`PowersUpBuilding`](/keys/powersupbuilding/) naming this type. Each plug the structure holds adds its [`Power=`](/keys/power/#scope-buildingtype) and superweapon to the structure. A plug's weapon replaces the structure's weapon in the same slot; when several plugs carry one, the earliest plug installed wins. [`PowersUpToLevel`](/keys/powersuptolevel/) covers a plug that fills several slots at once.

```ini title="rules.ini"
[MYPOWR]   ; example power plant that accepts one turbine
Upgrades=1

[MYTURBINE] ; example turbine plug
PowersUpBuilding=MYPOWR
Power=50
```

The count also sets how many sets of `PowerUp<n>` art settings are read for the type, starting with `PowerUp1Anim`. [Building animations](/systems/building-animations/#the-upgrade-slots-and-the-active-slots-share-one-array) covers where those settings go.

:::danger[Keep the value from 1 to 3 on a structure that takes plugs]
A structure has room to record three plugs. A type with a higher value accepts a fourth plug, and recording that plug overwrites other data the structure keeps, including its record of the last superweapon it launched. If the structure then launches a superweapon, the plug record is overwritten in turn, and the game can crash the next time it reads the structure's plugs. The fourth plug also replaces the type's first active animation, as [the shared animation slots](/systems/building-animations/#the-upgrade-slots-and-the-active-slots-share-one-array) explain.

A value of `0` does not refuse plugs. A structure at `0` accepts every plug that names its type, gains nothing from them, and can crash the game, as [`PowersUpBuilding`](/keys/powersupbuilding/) explains.
:::
