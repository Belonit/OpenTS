---
key: RepairBay
summary: The BuildingType that a vehicle on the Repair mission, or a damaged computer aircraft, heads for to be repaired.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "none"
---

```ini title="rules.ini"
[General]
RepairBay=GADEPOT   ; GADEPOT stands in for whichever BuildingType the mod uses

[GADEPOT]
UnitRepair=yes      ; without this, the named type turns every arrival away
```

A vehicle on the [`Repair` mission](/reference/enums/mission/) heads for the nearest building of exactly this type that meets all of these conditions:

- it belongs to the vehicle's house or an ally;
- it is not already serving another object;
- it lies in the same [movement zone](/glossary/#movement-zone) as the cell the vehicle stands in or is moving into;
- it accepts the vehicle.

The search runs only while the vehicle's house owns a building of this type, so a house uses an ally's depot only if it has one too. A damaged computer aircraft looking for repair uses the same search, without the movement-zone test. [Reaching the pad](/systems/repair/#reaching-the-pad) lists every route to a depot and its conditions, and the primary-factory exception to taking the nearest building.

Only this type is searched for. A player can still use a depot of another type by moving a vehicle onto it. A damaged computer vehicle also runs a separate search, which covers every [`UnitRepair=yes`](/keys/unitrepair/) building regardless of this setting.

Set [`UnitRepair=yes`](/keys/unitrepair/) on the type named here. Without it, the building refuses every vehicle, and a vehicle on the `Repair` mission keeps searching for as long as its house owns one.

This setting does not decide whether a selected player-controlled aircraft can enter a clicked building. That direct order accepts any idle, empty `UnitRepair=yes` building or helipad.

:::danger[Set `RepairBay` to a building type]
With no type named, the game crashes the first time any of these happens:

- a vehicle takes the `Repair` mission;
- a harvester or weeder runs out of places to harvest, whichever house owns it;
- a damaged computer aircraft looks for a repair bay.
:::
