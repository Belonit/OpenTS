---
key: DeploySound
scope: buildingtype
label: Structure build-up sound
see_also: [AuxSound1, UndeploySound]
when_omitted:
  kind: value
  value: none
  note: The structure plays its `AuxSound1` sound instead, or none when that key is unset too.
---

```ini title="rules.ini"
[MYSILO] ; a BuildingType registered in [BuildingTypes]
DeploySound=MYSILO_Buildup ; a sound ID registered in SOUND.INI
```

A structure plays this sound at its position when its construction animation begins, whichever house owns it.

:::caution[It replaces `AuxSound1`]
`DeploySound` and [`AuxSound1`](/keys/auxsound1/) set the same sound on a BuildingType, and `DeploySound` is read second. A type that sets both keeps only `DeploySound`. A name that matches no registered sound is ignored, so a misspelled `DeploySound` leaves the `AuxSound1` sound in place.
:::
