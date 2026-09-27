---
key: DropZoneRadius
summary: How far around a drop zone flare the map is revealed, in cells.
see_also: [DropZoneAnim, "system:map-visibility"]
when_omitted:
  kind: value
  value: "4"
  note: 1024 leptons.
---

```ini title="rules.ini"
[AudioVisual]
DropZoneRadius=6
```

`DropZoneRadius` sets how many cells around a [`DropZoneAnim`](/keys/dropzoneanim/) flare are revealed when the flare is created.

Only whole cells count: the value is cut down to a whole number, so `4.9` reveals 4 cells. The reveal stops at 10 cells however large the value. A value from `0` up to but not including `1` reveals nothing.

:::caution[Keep `DropZoneRadius` at `0` or above]
Exactly `-1` is read as if the key were absent, so it keeps the value an earlier rules file set. A value between `-1` and `0` reveals nothing. Any other value of `-1` or below makes the reveal read outside the game's table of reveal ranges, with unpredictable results.
:::
