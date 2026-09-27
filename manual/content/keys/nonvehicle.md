---
key: NonVehicle
summary: Stops a vehicle counting as a vehicle for repair weapons and for infantry that take vehicles over.
see_also: ["SmallVisceroid", "LargeVisceroid", "Jellyfish"]
when_omitted:
  kind: value
  value: "no"
---

`NonVehicle=yes` stops repair weapons and vehicle thieves from treating the type as a vehicle. Nothing else about the type changes: it is still a UnitType registered in `[VehicleTypes]`, and it still counts toward its owner's vehicle total.

Repair weapons cannot mend it. A weapon with negative [`Damage`](/keys/damage/) never picks the type as a target and is refused if ordered to fire at it, and the player gets no repair cursor over it. This covers mobile repair vehicles, mechanics and healers that mend both infantry and vehicles.

Infantry cannot take it over:

- a [`VehicleThief=yes`](/keys/vehiclethief/) soldier gets no enter cursor over it;
- a thief may not step into its cell, which is where a theft completes;
- infantry that do reach its cell do not take it over.

:::caution[A visceroid flag sets it regardless]
[`SmallVisceroid=yes`](/keys/smallvisceroid/#scope-unittype) or [`LargeVisceroid=yes`](/keys/largevisceroid/#scope-unittype) forces the flag on after this key has been read, so `NonVehicle=no` in a visceroid's section has no effect.
:::
