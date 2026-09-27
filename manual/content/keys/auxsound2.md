---
key: AuxSound2
summary: The sound a structure makes as it starts folding away, and the sound a flying object makes as it comes in to land.
see_also: [AuxSound1, UndeploySound, Locomotor]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[MYHELI] ; an AircraftType registered in [AircraftTypes]
AuxSound2=MYHELI_Landing ; a sound ID registered in SOUND.INI
```

Two unrelated events play this sound:

- A **structure** plays it at its position when it starts to fold away for a sale or an undeploy, just before its reverse build-up animation. An [`IsJuggernaut=yes`](/keys/isjuggernaut/) structure first turns its body and barrel back to their starting positions.
- An object moved by the flyer [locomotor](/keys/locomotor/) plays it once per landing, at the ground beneath it, when it descends below 300 leptons. An object with no strength left makes no landing sound.

On any other vehicle or infantry type the key has no effect.

:::caution[A structure's `UndeploySound` wins]
[`UndeploySound`](/keys/undeploysound/) sets the same sound and is read after `AuxSound2`. A BuildingType section that sets both plays only the `UndeploySound`. A rules file read later that sets only `AuxSound2` replaces it.
:::

A name that matches no sound ID is ignored and the sound set earlier stays. Writing `none` therefore cannot clear a sound that an earlier rules file set.
