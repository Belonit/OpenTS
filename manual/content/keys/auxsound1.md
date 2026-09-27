---
key: AuxSound1
summary: The sound a structure makes as its build-up starts, and the sound a flying object makes as it takes off.
see_also: [AuxSound2, DeploySound, Locomotor]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[MYHELI] ; an AircraftType registered in [AircraftTypes]
AuxSound1=MYHELI_Takeoff ; a sound ID registered in SOUND.INI
```

Two unrelated events play this sound at the object's position:

- A **structure** plays it when its build-up animation starts, whichever house owns it.
- An object moved by the flyer [locomotor](/keys/locomotor/) plays it each time it takes off, unless it is stunned.

On any other vehicle or infantry type the key has no effect.

:::caution[A structure's `DeploySound` wins]
[`DeploySound`](/keys/deploysound/#scope-buildingtype) sets the same sound and is read after `AuxSound1`. A BuildingType section that sets both plays only the `DeploySound`. A rules file read later that sets only `AuxSound1` replaces it.
:::

A name that matches no sound ID is ignored and the sound set earlier stays. Writing `none` therefore cannot clear a sound that an earlier rules file set.
