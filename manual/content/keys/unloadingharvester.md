---
key: UnloadingHarvester
summary: The vehicle type a harvester is drawn as while it stands at a refinery unloading.
see_also: [UnloadingClass, Harvester, Weeder, Dock, "system:tiberium"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
UnloadingHarvester=HORV ; a UnitType registered in [VehicleTypes]
```

A docked [`Harvester=yes`](/keys/harvester/#scope-unittype) vehicle is drawn as this vehicle type while it unloads. The swap starts once the harvester has turned to face east at the dock and lasts until it leaves. [Unloading](/systems/tiberium/#unloading) describes the docking.

A vehicle whose type sets [`UnloadingClass`](/keys/unloadingclass/) is drawn as that type instead. A [`Weeder=yes`](/keys/weeder/#scope-unittype) vehicle that is not also `Harvester=yes` ignores this setting and changes its artwork only through `UnloadingClass`.

With both settings unset, the harvester keeps its usual artwork while it unloads.

:::caution[Use a substitute built like the harvester]
Each frame of the unload draws the vehicle with the substitute type's settings: its artwork, whether it is a voxel or a shape, its turret and shadow, and for a shape its frame layout. A substitute not built to match the harvester can change more than its appearance, such as gaining or losing a turret or drawing the wrong frames.
:::
