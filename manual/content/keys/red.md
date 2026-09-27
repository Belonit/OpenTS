---
key: Red
summary: The scenario's red palette tint, where 1 leaves the red channel unchanged.
see_also: [Green, Blue, IonRed, "system:ion-storms"]
when_omitted:
  kind: value
  value: "1"
---

```ini title="map file"
[Lighting]
Red=1
Green=.9
Blue=.8
```

`Red` scales the red in the terrain's colors. `1` leaves red unchanged, a value above `1` adds red, and a value below `1` takes it away. `0` removes it. The value is kept in whole hundredths, rounded down, so `Red=.925` acts as `.92`. The tint is applied as the map loads, so it is in place from the first frame.

For each cell, the map's tint is added to the tint of any structure light that reaches the cell. [`LightRedTint`](/keys/lightredtint/) explains how the red, green and blue totals color and brighten the ground.

Units and structures are not tinted by `Red`. During an [ion storm](/systems/ion-storms/#lighting), terrain, units and structures all take the ion tint instead. [`IonRed`](/keys/ionred/) falls back to `Red`, so a map that sets only the ordinary tint keys keeps its terrain color through a storm, and its units and structures take that tint while the storm lasts.
