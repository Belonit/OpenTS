---
key: AllowedToStartInMultiplayer
summary: Lets a vehicle or infantry type appear in the starting forces each house receives outside a campaign or on a generated map.
see_also: [BaseUnit, Cost, TechLevel, Owner, "system:starting-forces"]
when_omitted:
  kind: value
  value: "yes"
---

`AllowedToStartInMultiplayer=no` keeps a type out of the [starting forces](/systems/starting-forces/) each house receives as a skirmish or multiplayer match begins, or as a generated map loads. Only UnitTypes and InfantryTypes are affected; a BuildingType or AircraftType ignores the key.

```ini title="rules.ini"
[MYSUPERTANK] ; a UnitType registered in [VehicleTypes]
AllowedToStartInMultiplayer=no
```

Denying a type has two effects:

- No house draws it. An allowed type is on a house's shortlist when its [`TechLevel`](/keys/techlevel/#scope-aircrafttype) is at or below the house's tech level and its [`Owner`](/keys/owner/) lists the house's country.
- Its [`Cost`](/keys/cost/#scope-aircrafttype) no longer counts toward the average price that sets every house's budget, so denying a type can raise or lower how much every house receives.

The [`BaseUnit`](/keys/baseunit/) types are never drawn and never count toward the average, whatever this key says.

:::caution[A house can end up short of its budget]
Denying every type makes every budget zero, so each house starts with its base unit alone, or with nothing when bases are off. Denying every InfantryType while vehicles stay allowed also leaves each house short. [Starting forces](/systems/starting-forces/#when-placement-fails) covers that case and the others where a house gets less than its budget.
:::
