---
key: IonLevel
scope: scenarios
label: Scenario lighting
see_also: [Level, IonGround, "system:ion-storms"]
when_omitted:
  kind: context-dependent
  note: The scenario's [Lighting] Level value with any fraction dropped, so any Level below 1 gives 0.
---

```ini title="map file"
[Lighting]
Level=.016
IonLevel=.016
```

While an ion storm runs, `IonLevel` replaces [`Level`](/keys/level/#scope-scenarios) as the brightness each height level adds to a cell. Larger values make cliffs and hills stand out more, and `0` shades the map flat. Aircraft in flight, and infantry and vehicles on bridges, also take their extra height brightness from `IonLevel` during a storm.

:::caution[Set IonLevel whenever the map sets Level]
A map that sets `Level` below `1` and omits `IonLevel` is shaded flat for the length of every storm, with cliffs and hills no brighter than the ground beside them. Write the value to both keys to keep the height shading during storms.
:::
