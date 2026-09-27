---
key: IonGround
scope: random-map-generation
label: Random map generation
see_also: [UseIonStorms, "system:ion-storms"]
when_omitted:
  kind: context-dependent
  note: "0, the same as a generated map's ground darkening outside storms, so storms add none."
---

Random map generation reads this key from the `[Lighting]` section of `ION.INI`, and only for a map whose seed sets [`UseIonStorms=yes`](/keys/useionstorms/). A loose `ION.INI` in the game directory takes precedence over one in a [MIX archive](/formats/mix/). The value applies to every generated map with ion storms.

The value works as [a scenario's `IonGround`](/keys/ionground/#scope-scenarios) does: while a storm runs, it is the fraction of full light subtracted from every cell. A generated map has no ground darkening outside storms, so any value above `0` makes storms darker than clear weather.

```ini title="ION.INI"
[Lighting]
IonGround=0  ; the stock file's value: no ground darkening during storms
```
