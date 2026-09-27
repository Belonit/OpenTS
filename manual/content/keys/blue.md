---
key: Blue
summary: The scenario's blue palette tint, where 1 leaves the blue channel unchanged.
see_also: [Red, Green, IonBlue, "system:ion-storms"]
when_omitted:
  kind: value
  value: "1"
---

```ini title="map file"
[Lighting]
Blue=.8
```

The value scales the blue in the tinted terrain palette that each cell's ground is drawn with, from the moment the map loads. A value below `1` takes blue out, and a value above `1` adds blue and also brightens the ground. [`LightRedTint`](/keys/lightredtint/) explains how the red, green and blue totals color and brighten the ground. The value is kept in whole hundredths, rounded down.

[House color schemes](/glossary/#color-scheme) are not tinted by this key; only an ion storm's tint reaches them. While a storm runs, [`IonBlue`](/keys/ionblue/#scope-scenarios) replaces this tint, and it defaults to this value.
