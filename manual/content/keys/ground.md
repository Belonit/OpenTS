---
key: Ground
summary: A flat darkening subtracted from every cell's brightness, as a fraction of full light.
see_also: [Level, IonGround, "system:ion-storms"]
when_omitted:
  kind: value
  value: "0"
---

```ini title="map file"
[Lighting]
Ground=.1
Level=.016
```

A cell's brightness is the ambient level set by [`Ambient`](/keys/ambient/), plus light from nearby light sources, plus [`Level`](/keys/level/#scope-scenarios) for each height level the cell stands at, minus this value. Raising it darkens every cell by the same amount: `.1` takes a tenth of full light off the whole map.

While an ion storm runs, [`IonGround`](/keys/ionground/#scope-scenarios) takes this value's place. An omitted `IonGround` keeps only the whole part of this value, so set `IonGround` as well to keep the darkening during a storm.
