---
key: IonBlue
scope: random-map-generation
label: Random map generation
see_also: [UseIonStorms, "system:ion-storms"]
when_omitted:
  kind: context-dependent
  note: 1, the generated map's `Blue` value, which leaves the blue channel unchanged.
---

Random map generation reads this entry from the `[Lighting]` section of `ION.INI`, and only when the [`UseIonStorms`](/keys/useionstorms/) option is on for the map being built. The file sets the storm lighting for every generated map. A loose `ION.INI` in the game directory takes precedence over one in an archive, as with any [game file](/formats/mix/).

The value is the storm's blue tint. It scales the blue channel of every terrain palette on the same scale as the [ordinary tint keys](/keys/blue/): `1` leaves the channel unchanged, a value above `1` adds blue, a value below `1` removes some, and `0` removes the channel. The engine clamps the value to the range `0` through `2`. The storm tints replace the map's ordinary tint on the frame the storm breaks and are removed on the frame it ends, as they are for [a scenario's `IonBlue`](/keys/ionblue/#scope-scenarios).

```ini title="ION.INI"
[Lighting]
IonBlue=0.34  ; the stock file's value: the storm removes most of the blue
```
