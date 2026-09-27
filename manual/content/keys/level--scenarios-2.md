---
key: Level
scope: scenarios-2
label: Height brightness
see_also: [Ground, IonLevel, "system:ion-storms"]
when_omitted:
  kind: value
  value: "0"
  note: An absent key gives 0, not the engine's starting value of about .016 (a sixtieth of full brightness), because the fallback is truncated to a whole number.
---

```ini title="map file"
[Lighting]
Level=.016
```

`Level` makes higher ground brighter. Each cell gains this value once for every height level it stands at. The value uses the same scale as [`Ambient`](/keys/ambient/), where `1` is full brightness, so `.016` adds 1.6 percent of full brightness per level. It is kept in thousandths, and any finer part is dropped.

[`Ground`](/keys/ground/) gives the full formula for a cell's brightness. At `0`, high ground is lit the same as low ground.

The same value brightens objects raised above the ground. An aircraft gains it once for every two height levels of altitude. A vehicle on a bridge gains four times this value, and an infantryman on a bridge gains nothing from it.

[`IonLevel`](/keys/ionlevel/) replaces this value while [an ion storm](/systems/ion-storms/#lighting) runs. Leaving `IonLevel` out does not carry this value over.
