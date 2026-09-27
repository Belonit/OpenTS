---
key: UnloadingClass
summary: The vehicle type a harvester of this type is drawn as while it unloads at a dock.
see_also: [UnloadingHarvester, Harvester, Weeder, Dock, UndeploysInto, "system:tiberium"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[HARV]
UnloadingClass=HORV ; a UnitType registered in [VehicleTypes]
```

While a harvester of this type unloads at a dock, it is drawn as the named vehicle type. The setting overrides the rules-wide [`UnloadingHarvester`](/keys/unloadingharvester/) for this type, so harvesters in the same game can each unload with different artwork. `UnloadingHarvester` describes when the swap starts and ends and what the substitute type controls. [Unloading](/systems/tiberium/#unloading) covers the docking.

Only a [`Harvester=yes`](/keys/harvester/#scope-unittype) or [`Weeder=yes`](/keys/weeder/#scope-unittype) vehicle uses the setting. A `Weeder=yes` vehicle that is not also `Harvester=yes` changes its artwork only through this key, because `UnloadingHarvester` does not apply to it.

A name that matches no registered UnitType registers a new, unconfigured vehicle under that name. The values `none` and `<none>` set no type, and clear a type an earlier rules file set. A `Harvester=yes` vehicle then uses `UnloadingHarvester`, and a weeder that is not also `Harvester=yes` keeps its usual artwork.
