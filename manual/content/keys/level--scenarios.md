---
key: Level
scope: scenarios
label: Map height offset
when_omitted:
  kind: value
  value: "0"
---

```ini title="map file"
[Map]
Level=1
```

`Level` raises the map's cells by that many height levels before the terrain is read. Each cell that the map's [terrain data](/formats/scenario-terrain/) lists then takes its height from that data, so the offset remains only on cells the data leaves out. A map whose terrain data lists every cell is not raised at all.

This key is unrelated to [`Level`](/keys/level/#scope-scenarios-2) in the `[Lighting]` section, which sets brightness.
