---
key: ExpSpread
summary: Divisor that turns an exploding object's collateral damage into the radius of its death blast.
see_also: ["Explodes", "CollateralDamageCoefficient", "Strength", "MaxDamage"]
when_omitted:
  kind: value
  value: ".5"
---

`ExpSpread` sets how wide the death blast of an exploding object reaches. A larger value makes a smaller blast.

An object explodes as it dies if its type sets [`Explodes=yes`](/keys/explodes/#scope-aircrafttype) or it has earned the [explodes ability](/systems/veterancy/#abilities). The blast is centered on the object. An object that falls from the air and dies on water does not explode.

The blast's strength is the object's collateral damage: its full [`Strength`](/keys/strength/#scope-aircrafttype) multiplied by its [`CollateralDamageCoefficient`](/keys/collateraldamagecoefficient/). Damage the object had already taken does not reduce it. A structure adds the Tiberium it stores: the amount of each Tiberium type multiplied by that type's [`Power`](/keys/power/#scope-tiberium). A full refinery therefore explodes harder than an empty one.

The blast uses the warhead of the object's primary weapon: [`Primary`](/keys/primary/), or [`Elite`](/keys/elite/) once the object is elite and `Elite` is set. A weapon that an [upgrade](/keys/upgrades/) supplies in that slot takes priority on a structure. An object with no weapon in that slot has no blast: no cell is damaged, and no explosion animation or flash appears.

## Radius

The radius in cells is the collateral damage divided by 100, rounded down, then divided by `ExpSpread`. The result is held between one [lepton](/glossary/#lepton) and three cells. Collateral damage below 100 therefore gives the smallest blast.

Set `ExpSpread` above `0`. A negative value gives the smallest blast, and `0` gives an undefined radius.

## Area and damage

The blast damages a square of cells centered on the object's cell. The square reaches the radius, rounded up to whole cells, in each direction: 3×3 cells at the smallest and 7×7 at the largest.

The blast's damage is the collateral damage multiplied by the radius rounded down to whole cells, and never less than the collateral damage itself. A radius between whole cells therefore reaches the next ring of cells but deals the damage of the smaller whole radius, as the example below shows.

```ini title="rules.ini"
[CombatDamage]
ExpSpread=.7
```

With this value, an object with 150 collateral damage has a radius of about 1.4 cells. Its blast covers 5×5 cells with a damage of 150. At `ExpSpread=.5`, the radius is exactly 2 cells: the blast covers the same 5×5 cells with a damage of 300.

:::caution[Damage grows toward the edge of a wide blast]
Each cell of the square sets off a separate explosion. The center cell's explosion carries the full blast damage. Every other cell's explosion carries a share of it: the cell's distance from the center, in whole cells rounded down, divided by the radius in cells rounded up. At a 2-cell radius, the cells one step out carry half the damage, and the cells two steps out carry all of it. At a 3-cell radius, the four corner cells are more than three steps out and carry a third more than the full damage. In a 3×3 blast, every cell carries the full damage.

Each of these explosions also reaches objects in the [eight cells around it](/systems/warheads/#the-nine-cells), reduced by armor and by [distance](/systems/warheads/#how-distance-thins-the-damage). An object inside the blast is therefore hit by its cell's explosion and by those of the neighboring blast cells, and takes more than its cell's share.
:::
