---
key: IonGround
scope: scenarios
label: Scenario lighting
see_also: [Ground, IonLevel, "system:ion-storms"]
when_omitted:
  kind: context-dependent
  note: This scenario's Ground value with any fraction dropped, so every Ground value below 1 gives 0.
---

```ini title="map file"
[Lighting]
Ground=.1
IonGround=.1
```

While an ion storm runs, `IonGround` replaces [`Ground`](/keys/ground/) as the light subtracted from every cell. It uses the same scale, a fraction of full light, so `0` darkens nothing and `.1` removes a tenth of full light. `IonGround` takes over on the frame the storm breaks, and `Ground` returns on the frame it ends. Neither change fades.

:::caution[Set IonGround whenever the map sets Ground]
A map that sets `Ground` below `1` and omits `IonGround` has no ground darkening for the length of every storm. Write the value to both keys to keep the darkening during storms.
:::
