---
key: Selectable
scope: aircrafttype
label: Player selection
when_omitted:
  kind: context-dependent
  note: An AircraftType, BuildingType, InfantryType, UnitType, ParticleType, ParticleSystemType or VoxelAnimType section starts at yes. A BulletType, OverlayType, SmudgeType or TerrainType section starts at no.
---

`Selectable=no` stops the player from selecting any object of this type by any means. Clicking it, drawing a [band box](/systems/band-selection/) across it, and cycling through the army with the next- and previous-object commands all pass it by. The cursor over it never becomes the select cursor.

```ini title="rules.ini"
[MYORCA] ; example AircraftType
Selectable=no
```

The setting has three further effects:

- Pointing at an object of this type never shows its health bar.
- In power mode, the cursor refuses to toggle the power of a structure of this type.
- An aircraft of this type becomes a [loaner](/keys/landable/#what-a-loaner-does) when it enters the map. A loaner may leave the map, and when idle it never settles into guard.
