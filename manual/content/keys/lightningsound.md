---
key: LightningSound
summary: Selects the sound played by each ion storm lightning bolt.
see_also: [IonLightningDamage, "system:ion-storms"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
LightningSound=IonThunder ; a sound registered in [SoundList]
```

Each lightning bolt plays this sound once as it strikes. The sound has no position on the map, so every bolt sounds the same wherever it lands and wherever the view is. Bolts from the [Lightning strike at...](/mapping/actions/taction-ion-lightning-strike/) trigger action play it too.
