---
key: FreeRadar
summary: Whether the scenario grants the radar map without a radar structure.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="map file"
[Basic]
FreeRadar=yes
```

The player has the radar map without owning a working [`Radar=yes`](/keys/radar/) structure. The radar map still goes off during an ion storm and while the player's house uses more power than it produces.
