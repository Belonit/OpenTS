---
key: Crusher
summary: Lets a vehicle drive over crushable objects and walls instead of being blocked by them.
see_also: ["AutoCrush", "TiltsWhenCrushes", "Crushable", "SpeedType"]
when_omitted:
  kind: value
  value: "no"
---

A vehicle with the flag drives over a non-allied [`Crushable=yes`](/keys/crushable/#scope-aircrafttype) object and treats its cell as passable. Without the flag, the vehicle must shoot the object or go around it. A vehicle whose rank grants the crusher ability from [`VeteranAbilities`](/keys/veteranabilities/) crushes the same way.

The flag also lets a vehicle that cannot fire act on a crushable enemy. Clicking the enemy gives a move order, and the vehicle drives over it. Without the flag the click only selects the enemy.

A crushable wall of another house is passable to a crusher. When routes are planned, a crushable wall of the crusher's own house or an ally counts as an obstacle the crusher can destroy, not as solid wall. Driving onto any crushable wall removes the segment, whatever its owner and damage stage. [Crushing, clearing and selling](/systems/walls-and-gates/#crushing-clearing-and-selling) covers the rest.

On a UnitType, the flag also sets the default [terrain speed class](/reference/enums/speed-type/). The first rules file that contains the type's section gives it `Track` with the flag and `Wheel` without it. A [`SpeedType=`](/keys/speedtype/) in the same section overrides that choice, and a later change to `Crusher=` does not change the class.

Other settings build on the flag:

- [`Crush=`](/keys/crush/) sets how close a crushable target must be before a computer-controlled crusher drives over it instead of firing.
- [`[IQ] AutoCrush=`](/keys/autocrush/#scope-global-rules) sets the IQ a computer house needs before its crushers run over their attackers. The per-type [`AutoCrush`](/keys/autocrush/#scope-aircrafttype) flag has no effect.
- [`TiltsWhenCrushes`](/keys/tiltswhencrushes/) decides whether the hull tilts while the vehicle crushes sandbag wall.

A BuildingType accepts the key, but it has no effect. On an InfantryType or AircraftType it has an effect only when the type's [`Locomotor`](/keys/locomotor/) is the drive or mech locomotor, and then only on sandbag walls.
