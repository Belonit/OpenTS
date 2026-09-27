---
key: IonAmbient
scope: scenarios
label: Scenario lighting
see_also: [Ambient, AmbientChangeRate, "system:ion-storms"]
when_omitted:
  kind: context-dependent
  note: The value this scenario's Ambient key sets, read before it in the same section. With neither key present that is 1, full daylight.
---

```ini title="map file"
[Lighting]
Ambient=1
IonAmbient=.5
```

When a storm breaks, [the ambient fade](/systems/ion-storms/#the-ambient-ramp) moves the map's light level toward this value in steps. When the storm ends, the fade moves it back to [`Ambient`](/keys/ambient/), or to the level a [Set ambient light...](/mapping/actions/taction-set-ambient-light/) action stored during the storm. The storm's tint changes in one step, so a map with a low `IonAmbient` shows its storm colors before it reaches its storm darkness.
