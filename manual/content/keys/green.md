---
key: Green
summary: The scenario's green palette tint, where 1 leaves the green channel unchanged.
see_also: [Red, Blue, IonGreen, "system:ion-storms"]
when_omitted:
  kind: value
  value: "1"
---

```ini title="map file"
[Lighting]
Green=.9
```

This value scales the green channel of the terrain palette that each cell's ground is drawn through, from the moment the map loads. `.9` takes a tenth of the green out of the ground. The value is kept in whole hundredths, rounded down.

[House color schemes](/glossary/#color-scheme) are not tinted by this key; only an ion storm's tint reaches them. While a storm runs, [`IonGreen`](/keys/iongreen/#scope-scenarios) replaces this tint.
