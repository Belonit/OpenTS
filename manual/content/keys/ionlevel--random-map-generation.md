---
key: IonLevel
scope: random-map-generation
label: Random map generation
see_also: [UseIonStorms, "system:ion-storms"]
when_omitted:
  kind: context-dependent
  note: "0, so storms shade the map flat. Outside storms a generated map adds only a thousandth of full light per height level."
---

Random map generation reads this key from the `[Lighting]` section of `ION.INI`, and only for a map whose seed sets [`UseIonStorms=yes`](/keys/useionstorms/). A loose `ION.INI` in the game directory takes precedence over one in a [MIX archive](/formats/mix/). The value applies to every generated map with ion storms.

The value works as [a scenario's `IonLevel`](/keys/ionlevel/#scope-scenarios) does: while a storm runs, it is the brightness each height level adds to a cell, as a fraction of full light. Larger values make cliffs and hills stand out more, and `0` shades the map flat. Aircraft in flight, and infantry and vehicles on bridges, also take their extra height brightness from it during a storm.

```ini title="ION.INI"
[Lighting]
IonLevel=0  ; the stock file's value: storms shade the map flat
```
