---
key: IonAmbient
scope: random-map-generation
label: Random map generation
see_also: [UseIonStorms, "system:ion-storms"]
when_omitted:
  kind: context-dependent
  note: The time-of-day light level of the generated map. On most maps that is the light the map opens at; in an arctic theater such as SNOW it is a third brighter.
---

Random map generation reads this entry from the `[Lighting]` section of `ION.INI`, and only when the [`UseIonStorms`](/keys/useionstorms/) option is on for the map being built. The file sets the storm lighting for every generated map. A loose `ION.INI` in the game directory takes precedence over one in an archive, as with any [game file](/formats/mix/).

The value is the light level a storm fades the map to, on the [`Ambient`](/keys/ambient/) scale where `1` is full daylight and `0` is no ambient light. [The ambient fade](/systems/ion-storms/#the-ambient-ramp) moves the map to this level when a storm breaks, as it does for [a scenario's `IonAmbient`](/keys/ionambient/#scope-scenarios).

When the storm ends, the map fades back to its time-of-day light level. In an [arctic theater](/keys/isarctic/#scope-theater) such as SNOW, the map opens at three quarters of that level, so it ends a storm a third brighter than it began. With [`UseTransitions`](/keys/usetransitions/) on, a transition that has already fired sets the level the map returns to instead.

```ini title="ION.INI"
[Lighting]
IonAmbient=0.5  ; the stock file's value: storms fade to half daylight
```
