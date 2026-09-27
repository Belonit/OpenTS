---
key: UndeploySound
summary: The sound a structure makes as its deconstruction starts.
see_also: [AuxSound2, DeploySound, IsJuggernaut, SellSound]
when_omitted:
  kind: value
  value: none
  note: The slot holds whatever [`AuxSound2`](/keys/auxsound2/) put there, and nothing at all when that key is unset too.
---

```ini title="rules.ini"
[MYUNDEPLOY] ; a BuildingType registered in [BuildingTypes]
UndeploySound=MYUP1 ; a sound ID registered in SOUND.INI
```

A structure plays this sound at its position when it starts to deconstruct, whether it is being sold or undeployed. It is the first sound of the deconstruction. Any crew evacuation and the [`SellSound`](/keys/sellsound/) come after it, and then the reverse build-up.

The structure stops every animation running on it as the sound plays. An [`IsJuggernaut=yes`](/keys/isjuggernaut/) structure first turns its body and barrel back to [`StartFacing`](/keys/startfacing/) and [`StartPitch`](/keys/startpitch/), and plays the sound once it gets there.

Two sell orders stop short of deconstruction and play no `UndeploySound`:

- Selling a structure that holds an upgrade plug sells its most recent plug instead.
- Selling a [`UnitRepair=yes`](/keys/unitrepair/) service depot with an object parked on it sells that object instead.

:::caution[Set either `UndeploySound` or `AuxSound2`, not both]
`UndeploySound` and [`AuxSound2`](/keys/auxsound2/) set the same sound, and `UndeploySound` is read second. A BuildingType that sets both keeps only `UndeploySound`. A name that matches no registered sound is ignored, so the earlier value stays in place.
:::
