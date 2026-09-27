---
key: IonRed
scope: random-map-generation
label: Random map generation
see_also: [UseIonStorms, "system:ion-storms"]
when_omitted:
  kind: context-dependent
  note: "1, which leaves the red channel unchanged, because a generated map's ordinary red tint is always 1."
---

Random map generation reads this key from the `[Lighting]` section of `ION.INI`, and only for a map whose seed sets [`UseIonStorms=yes`](/keys/useionstorms/). A loose `ION.INI` in the game directory takes precedence over one in a [MIX archive](/formats/mix/). The value applies to every generated map with ion storms.

The value is the storm's red tint, and it works as [a scenario's `IonRed`](/keys/ionred/#scope-scenarios) does.

```ini title="ION.INI"
[Lighting]
IonRed=1.62  ; the stock file's value
```
